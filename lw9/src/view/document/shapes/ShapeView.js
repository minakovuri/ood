import {DispatcherComponent} from "../../common/DispatcherComponent.js"
import {Rect} from "../../../common/Types.js"
import {Events} from "./Events.js"

/** @typedef {'triangle'|'rectangle'|'ellipse'}*/
let ShapeType

class ShapeView extends DispatcherComponent {
    /**
     * @param {Rect} rect
     * @param {string} id
     */
    constructor(rect, id) {
        super();

        /**
         * @type {string}
         * @private
         */
        this._id = id

        /**
         * @type {Rect}
         */
        this.state.rect = rect
    }

    /**
     * @return {string}
     */
    getId() {
        return this._id
    }

    /**
     * @param {Rect} rect
     */
    setRect(rect) {
        this.setState({
            rect: rect,
        })
    }

    /**
     * @return {Rect}
     */
    getRect() {
        return this.state.rect
    }

    /**
     * @abstract
     */
    render() {}

    /**
     * @param {MouseEvent} e
     * @protected
     */
    onmousedown(e) {
        e.preventDefault()
        this.dispatchEvent(Events.ONCLICK)

        const shape = e.target

        const rect = this.getRect()

        const innerOffsetX = e.pageX - rect.left
        const innerOffsetY = e.pageY -rect.top

        shape.ondragstart = () => {
            return false
        }

        document.onmousemove = (e) => {
            const newLeft = e.pageX - innerOffsetX
            const newTop = e.pageY - innerOffsetY

            this.dispatchEvent(Events.DRAGGED, {
                top: newTop,
                left: newLeft,
            })
        }

        shape.onmouseup = () => {
            document.onmousemove = null
            shape.onmouseup = null
        }
    }
}

export {
    ShapeType,
    ShapeView,
}