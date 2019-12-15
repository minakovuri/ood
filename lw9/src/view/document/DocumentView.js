import {ShapeView} from "./shapes/ShapeView.js"
import {Frame} from "./frame/Frame.js"
import {ViewRect} from "../types/ViewRect.js"
import {ShapeEvents} from "./shapes/Events.js"
import {DocumentEvents} from "./Events.js"
import {ShapesFactory} from "./shapes/ShapesFactory.js"
import {DispatcherComponent} from "../common/DispatcherComponent.js"
import {FrameEvents} from "./frame/Events.js"
import {KeyCodes} from "../common/KeyCodes.js"
import {ViewShapeType} from "./shapes/ShapeType.js"

const DocumentOptions = {
    WIDTH: 1500,
    HEIGHT: 800,
}

class DocumentView extends DispatcherComponent {
    constructor() {
        super();

        /**
         * @type {Array<ShapeView>}
         */
        this.state.shapes = []

        /**
         * @type {Array<Frame>}
         */
        this.state.frames = []

        /**
         * @type {?string}
         * @private
         */
        this._selectedShapeId = null

        this._listenDeleteShapeEvent()

        this._listenUnselectShapes()
    }

    /**
     * @param {string} id
     * @param {ViewRect} rect
     * @param {ViewShapeType} type
     */
    addShape(id, rect, type) {
        const frame = new Frame(id, rect)
        const shape = ShapesFactory.createShape(rect, id, type)

        const shapeId = shape.getId()

        frame.addListener(FrameEvents.RESIZE, ({ left, top, width, height }) => {
            const currentRect = shape.getRect()

            const bottom = top + height
            const right = left + width

            if (top <= 0) {
                top = 1
                height = currentRect.height
            } else if (bottom >= DocumentOptions.HEIGHT) {
                height = DocumentOptions.HEIGHT - 1 - top
            }

            if (left <= 0) {
                left = 1
                width = currentRect.width
            } else if (right >= DocumentOptions.WIDTH) {
                width = DocumentOptions.WIDTH - 1 - left
            }

            const newRect = {
                top,
                left,
                width,
                height,
            }

            this.dispatchEvent(DocumentEvents.UPDATE_SHAPE_RECT, {
                shapeId,
                newRect,
            })
        })

        shape.addListener(ShapeEvents.ONCLICK, () => {
            this._selectedShapeId = shapeId

            for (const currFrame of this.state.frames) {
                currFrame.getEnabled() && currFrame.setEnabled(false)
            }

            !frame.getEnabled() && frame.setEnabled(true)

            let shapes = this.state.shapes
            shapes = shapes.filter(currShape => currShape !== shape)
            shapes.push(shape)

            this.setState({
                shapes,
                frames: this.state.frames,
            })
        })

        shape.addListener(ShapeEvents.DRAGGED, ({ top, left }) => {
            const currentRect = shape.getRect()

            const bottom = top + currentRect.height
            const right = left + currentRect.width

            if (top <= 0) {
                top = 1
            } else if (bottom >= DocumentOptions.HEIGHT) {
                top = DocumentOptions.HEIGHT - currentRect.height - 1
            }

            if (left <= 0) {
                left = 1
            } else if (right >= DocumentOptions.WIDTH) {
                left = DocumentOptions.WIDTH - currentRect.width - 1
            }

            const newRect = {
                top,
                left,
                width: currentRect.width,
                height: currentRect.height,
            }

            this.dispatchEvent(DocumentEvents.UPDATE_SHAPE_RECT, {
                shapeId,
                newRect,
            })
        })

        this.setState({
            shapes: this.state.shapes.concat(shape),
            frames: this.state.frames.concat(frame),
        })
    }

    /**
     * @param {string} shapeId
     * @param {ViewRect} rect
     */
    updateShape(shapeId, rect) {
        const frames = this.state.frames
        const shapes = this.state.shapes

        const frameIndex = frames.findIndex(frame => frame.getShapeId() == shapeId)
        if (frameIndex == -1) {
            throw new Error(`cannot find frame for shape with id : ${shapeId}`)
        }
        frames[frameIndex].setRect(rect)

        const shapeIndex = shapes.findIndex(shape => shape.getId() == shapeId)
        if (shapeIndex == -1) {
            throw new Error(`cannot find shape with id : ${shapeId}`)
        }
        shapes[shapeIndex].setRect(rect)

        this.setState({
            shapes,
            frames,
        })
    }

    /**
     * @param {string} shapeId
     */
    removeShape(shapeId) {
        if (this._selectedShapeId == shapeId) {
            this._selectedShapeId = null
        }

        const frames = this.state.frames
        const shapes = this.state.shapes

        const frameIndex = frames.findIndex(frame => frame.getShapeId() == shapeId)
        if (frameIndex == -1) {
            throw new Error(`cannot find frame for shape with id : ${shapeId}`)
        }
        frames.splice(frameIndex, 1)

        const shapeIndex = shapes.findIndex(shape => shape.getId() == shapeId)
        if (shapeIndex == -1) {
            throw new Error(`cannot find shape with id : ${shapeId}`)
        }
        shapes.splice(shapeIndex, 1)

        this.setState({
            shapes,
            frames,
        })
    }

    /**
     * @return {?string}
     */
    getSelectedShapeId() {
        return this._selectedShapeId
    }

    render() {
        return this.html`
<div class="document" style=${{ width: DocumentOptions.WIDTH, height: DocumentOptions.HEIGHT }}>
    <div class="frames-layer">
        ${this.state.frames.map(frame => frame.render())}
    </div>
    <svg class="shapes-layer">
        ${this.state.shapes.map(shape => shape.render())}
    </svg>
</div>`
    }

    /**
     * @private
     */
    _listenDeleteShapeEvent() {
        document.onkeydown = (e) => {
            if (e.defaultPrevented) {
                return
            }

            if (e.keyCode == KeyCodes.BACK_SPACE && this._selectedShapeId) {
                this.dispatchEvent(DocumentEvents.DELETE_SHAPE)
            }
        }
    }

    /**
     * @private
     */
    _listenUnselectShapes() {
        document.onmousedown = (e) => {
            if (e.defaultPrevented) {
                return
            }

            this._selectedShapeId = null

            for (const frame of this.state.frames) {
                frame.getEnabled() && frame.setEnabled(false)
            }
        }
    }
}

export {
    DocumentView,
}