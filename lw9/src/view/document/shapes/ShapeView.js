import {DispatcherComponent} from "../../common/DispatcherComponent.js"
import {ViewRect} from "../../types/ViewRect.js"
import {ShapeEvents} from "./Events.js"

class ShapeView extends DispatcherComponent {
    /**
     * @param {ViewRect} rect
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
         * @type {ViewRect}
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
     * @param {ViewRect} rect
     */
    setRect(rect) {
        this.setState({
            rect: rect,
        })
    }

    /**
     * @return {ViewRect}
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
        this.dispatchEvent(ShapeEvents.ONCLICK)

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

            this.dispatchEvent(ShapeEvents.DRAGGED, {
                top: newTop,
                left: newLeft,
            })
        }

        document.onmouseup = () => {
            document.onmousemove = null
            shape.onmouseup = null
        }
    }
}

export {
    ShapeView,
}