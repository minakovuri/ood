import {hyper} from "hyperhtml"
import {Rect} from "../../common/Types.js"

const SHAPE_RESIZE_HANDLE_SIDE = 6

class ShapeView extends hyper.Component {
    /**
     * @param {Rect} frame
     * @param {string} id
     */
    constructor(frame, id) {
        super();

        /**
         * @protected
         */
        this._frame = frame

        /**
         * @private
         */
        this._id = id
    }

    /**
     * @return {string}
     */
    getId() {
        return this._id
    }

    /**
     * @param {Rect} frame
     */
    setFrame(frame) {
        this._frame = frame
        this.render()
    }

    render() {
        return this._renderImpl()
    }

    /**
     * @abstract
     * @protected
     */
    _renderImpl() {}

    /**
     * @protected
     */
    _renderFocusedRect() {
        const frame = this._frame

        const topLeft = { x: frame.left, y: frame.top }
        const topRight = { x: frame.left + frame.width, y: frame.top }
        const bottomLeft = { x: frame.left, y: frame.top + frame.height }
        const bottomRight = { x: frame.left + frame.width, y: frame.top + frame.height }

        const topLeftResizeHandler = {
            x: topLeft.x - SHAPE_RESIZE_HANDLE_SIDE / 2,
            y: topLeft.y - SHAPE_RESIZE_HANDLE_SIDE / 2,
        }

        const topMiddleResizeHandler = {
            x: topLeft.x + frame.width / 2 - SHAPE_RESIZE_HANDLE_SIDE / 2,
            y: topLeft.y - SHAPE_RESIZE_HANDLE_SIDE / 2,
        }

        return hyper.wire()`
<svg>
    <line x1="${topLeft.x}" y1="${topLeft.y}" x2="${bottomLeft.x}" y2="${bottomLeft.y}" class="rect-border"></line>
    <line x1="${topLeft.x}" y1="${topLeft.y}" x2="${topRight.x}" y2="${topRight.y}" class="rect-border"></line>
    <line x1="${topRight.x}" y1="${topRight.y}" x2="${bottomRight.x}" y2="${bottomRight.y}" class="rect-border"></line>
    <line x1="${bottomRight.x}" y1="${bottomRight.y}" x2="${bottomLeft.x}" y2="${bottomLeft.y}" class="rect-border"></line>
    <rect 
        x="${topLeftResizeHandler.x}" y="${topLeftResizeHandler.y}" 
        width="${SHAPE_RESIZE_HANDLE_SIDE}" height="${SHAPE_RESIZE_HANDLE_SIDE}"
        class="resize-handler left-diagonal-resize-handler"
    ></rect>
    <rect 
        x="${topMiddleResizeHandler.x}" y="${topMiddleResizeHandler.y}" 
        width="${SHAPE_RESIZE_HANDLE_SIDE}" height="${SHAPE_RESIZE_HANDLE_SIDE}"
        class="resize-handler vertical-resize-handler"
    ></rect>
    )}
</svg>`
    }
}

export {
    ShapeView,
}