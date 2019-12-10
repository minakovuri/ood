import {hyper} from "hyperhtml"
import {ShapeView, ShapeType} from "./shapes/ShapeView.js"
import {Frame} from "./frame/Frame.js"
import {Rect} from "../../common/Types.js"
import {Events} from "./shapes/Events.js"
import {ShapesFactory} from "./shapes/ShapesFactory.js"

class DocumentView extends hyper.Component{
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
         * @param {Event} e
         */
        window.onclick = (e) => {
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
        const shapes = this.state.shapes
        const frames = this.state.frames

        const frame = new Frame(id, rect)
        const shape = ShapesFactory.createShape(rect, id, type)

        shape.addListener(Events.ONCLICK, () => {
            !frame.getEnabled() && frame.setEnabled(true)
        })

        shapes.push(shape)
        frames.push(frame)

        this.setState({
            shapes: shapes,
            frames: frames,
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