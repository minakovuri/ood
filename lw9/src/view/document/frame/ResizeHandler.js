import {hyper} from "hyperhtml"

const SHAPE_RESIZE_HANDLE_SIDE = 6

class ResizeHandler extends hyper.Component {
    /**
     * @param {'left-diagonal'|'vertical'|'right-diagonal'|'horizontal'} type // TODO: вынести в enum
     * @param {function({ x: number, y: number }): void} onDrag
     */
    constructor(type, onDrag) {
        super();

        /**
         * @type {number}
         */
        this.state.x = 0

        /**
         * @type {number}
         */
        this.state.y = 0

        this._type = type
        this._onDrag = onDrag
    }

    /**
     * @param {number} x
     * @param {number} y
     */
    update({ x,y }) {
        const newCoordinates = {
            x: x - SHAPE_RESIZE_HANDLE_SIDE / 2,
            y: y - SHAPE_RESIZE_HANDLE_SIDE / 2,
        }
        this.setState(newCoordinates)
    }

    render() {
        return this.html`
<svg class="resize-handler-wrapper">
    <rect
        class="resize-handler ${this._type}"
        x=${this.state.x} y=${this.state.y}
        width=${SHAPE_RESIZE_HANDLE_SIDE} height=${SHAPE_RESIZE_HANDLE_SIDE}
        onmousedown=${this}
    ></rect>
</svg>`
    }

    /**
     * @param {MouseEvent} e
     */
    onmousedown(e) {
        e.preventDefault()

        const handler = e.target

        const centerX = this.state.x + SHAPE_RESIZE_HANDLE_SIDE / 2
        const centerY = this.state.y + SHAPE_RESIZE_HANDLE_SIDE / 2

        const innerOffsetX = e.pageX - centerX
        const innerOffsetY = e.pageY - centerY

        handler.ondragstart = () => {
            return false
        }

        document.onmousemove = (e) => {
            this._onDrag({
                x: e.pageX - innerOffsetX,
                y: e.pageY - innerOffsetY,
            })
        }

        document.onmouseup = () => {
            document.onmousemove = null
            handler.onmouseup = null
        }
    }
}

export {
    ResizeHandler,
}