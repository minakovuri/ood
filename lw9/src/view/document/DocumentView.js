import {ShapeView, ShapeType} from "./shapes/ShapeView.js"
import {Frame} from "./frame/Frame.js"
import {Rect} from "../../common/Types.js"
import {Events} from "./shapes/Events.js"
import {DocumentEvents} from "./Events.js"
import {ShapesFactory} from "./shapes/ShapesFactory.js"
import {DispatcherComponent} from "../common/DispatcherComponent.js"
import {FrameEvents} from "./frame/Events.js"

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

        window.onmousedown = (e) => {
            if (e.defaultPrevented) {
                return
            }

            for (const frame of this.state.frames) {
                frame.getEnabled() && frame.setEnabled(false)
            }
        }
    }

    /**
     * @param {Rect} rect
     * @param {string} id
     * @param {ShapeType} type
     */
    addShape(rect, id, type) {
        const frame = new Frame(id, rect)
        const shape = ShapesFactory.createShape(rect, id, type)

        const shapeId = shape.getId()

        frame.addListener(FrameEvents.RESIZE, (newRect) => {
            this.dispatchEvent(DocumentEvents.CHANGE_RECT, {
                shapeId,
                newRect,
            })
        })

        shape.addListener(Events.ONCLICK, () => {
            for (const currFrame of this.state.frames) {
                currFrame.getEnabled() && currFrame.setEnabled(false)
            }

            !frame.getEnabled() && frame.setEnabled(true)

            /**
             * @type {Array<ShapeView>}
             */
            let shapes = this.state.shapes
            shapes = shapes.filter(currShape => currShape !== shape)
            shapes.push(shape)

            this.setState({
                shapes,
                frames: this.state.frames,
            })
        })

        shape.addListener(Events.DRAGGED, ({ top, left }) => {
            const currentRect = shape.getRect()

            /**
             * @type {Rect}
             */
            const newRect = {
                top,
                left,
                width: currentRect.width,
                height: currentRect.height,
            }

            this.dispatchEvent(DocumentEvents.CHANGE_RECT, {
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
     * @param {Rect} rect
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

    render() {
        return this.html`
<div class="document">
    <div class="frames-layer">
        ${this.state.frames.map(frame => frame.render())}
    </div>
    <svg class="shapes-layer" width="1200" height="600">
        ${this.state.shapes.map(shape => shape.render())}
    </svg>
</div>`
    }
}

export {
    DocumentView,
}