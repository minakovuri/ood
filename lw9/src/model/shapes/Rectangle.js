import {Shape} from "./Shape"
import {Point} from "../types/Point.js"
import {Rect} from "../types/Rect.js"

class Rectangle extends Shape {
    /**
     * @param {Rect} rect
     */
    constructor(rect) {
        super()

        /**
         * @type {Point}
         * @private
         */
        this._leftTop = { x: rect.left, y: rect.top }

        /**
         * @type {Point}
         * @private
         */
        this._rightBottom = { x: rect.left + rect.width, y: rect.top + rect.height }
    }

    /**
     * @override
     * @private
     */
    _getTypeImpl() {
        return 'rectangle'
    }

    /**
     * @override
     * @private
     */
    _getRectImpl() {
        const left = this._leftTop.x
        const top = this._leftTop.y

        const width = Math.abs(this._rightBottom.x - this._leftTop.x)
        const height = Math.abs(this._rightBottom.y - this._leftTop.y)

        return {
            left,
            top,
            width,
            height,
        }
    }

    /**
     * @override
     * @private
     */
    _setRectImpl(rect) {
        this._leftTop = { x: rect.left, y: rect.top}
        this._rightBottom = { x: rect.left + rect.width, y: rect.top + rect.height }
    }
}

export {
    Rectangle,
}