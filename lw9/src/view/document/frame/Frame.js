import {hyper} from "hyperhtml"
import {Rect} from "../../../common/Types.js"

const SHAPE_RESIZE_HANDLE_SIDE = 6

class Frame extends hyper.Component {
    /**
     * @param {string} shapeId
     * @param {Rect} rect
     */
    constructor(shapeId, rect) {
        super();

        /**
         * @type {string}
         * @private
         */
        this._shapeId = shapeId

        this.state.rect = rect
        this.state.enable = false
    }

    /**
     * @return {string}
     */
    getShapeId() {
        return this._shapeId
    }

    /**
     * @param {Rect} rect
     */
    setRect(rect) {
        const newState = {
            shapeId: this.state.shapeId,
            rect: rect,
            enable: this.state.enable,
        }
        this.setState(newState)
    }

    /**
     * @return {Rect}
     */
    getRect() {
        return this.state.rect
    }

    /**
     * @param {boolean} enable
     */
    setEnabled(enable) {
        const newState = {
            shapeId: this.state.shapeId,
            rect: this.state.rect,
            enable: enable,
        }
        this.setState(newState)
    }

    /**
     * @return {boolean}
     */
    getEnabled() {
        return this.state.enable
    }

    render() {
        const rect = this.state.rect

        const topLeft = { x: rect.left, y: rect.top }
        const topRight = { x: rect.left + rect.width, y: rect.top }
        const bottomLeft = { x: rect.left, y: rect.top + rect.height }
        const bottomRight = { x: rect.left + rect.width, y: rect.top + rect.height }

        const topLeftResizeHandler = {
            x: topLeft.x - SHAPE_RESIZE_HANDLE_SIDE / 2,
            y: topLeft.y - SHAPE_RESIZE_HANDLE_SIDE / 2,
        }

        const topMiddleResizeHandler = {
            x: topLeft.x + rect.width / 2 - SHAPE_RESIZE_HANDLE_SIDE / 2,
            y: topLeft.y - SHAPE_RESIZE_HANDLE_SIDE / 2,
        }

        return this.html`
            ${ !this.state.enable ? null : hyper.wire()`
<svg class="frame">
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
    }`}
}

export {
    Frame,
}