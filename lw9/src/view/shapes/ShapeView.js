import {hyper} from "hyperhtml"
import {Rect} from "../../common/Types.js"

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
     * @private
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

        return hyper.wire()`
<svg>
    <line x1="${topLeft.x}" y1="${topLeft.y}" x2="${bottomLeft.x}" y2="${bottomLeft.y}" class="rect-border horizontal-resize"></line>
    <line x1="${topLeft.x}" y1="${topLeft.y}" x2="${topRight.x}" y2="${topRight.y}" class="rect-border vertical-resize"></line>
    <line x1="${topRight.x}" y1="${topRight.y}" x2="${bottomRight.x}" y2="${bottomRight.y}" class="rect-border horizontal-resize"></line>
    <line x1="${bottomRight.x}" y1="${bottomRight.y}" x2="${bottomLeft.x}" y2="${bottomLeft.y}" class="rect-border vertical-resize"></line>
</svg>`
    }
}

export {
    ShapeView,
}