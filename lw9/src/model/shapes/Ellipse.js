import {Shape} from "./Shape"
import {Rect} from "../types/Rect.js"
import {Point} from "../types/Point.js"

class Ellipse extends Shape {
    /**
     * @param {Rect} rect
     */
    constructor(rect) {
        super()

        /**
         * @type {number}
         * @private
         */
        this._horizontalRadius = rect.width / 2

        /**
         * @type {number}
         * @private
         */
        this._verticalRadius = rect.height / 2

        /**
         * @type {Point}
         * @private
         */
        this._center = { x: rect.left + this._horizontalRadius, y: rect.top + this._verticalRadius }
    }

    /**
     * @override
     * @private
     */
    _getTypeImpl() {
        return 'ellipse'
    }

    /**
     * @override
     * @private
     */
    _getRectImpl() {
        const left = this._center.x - this._horizontalRadius
        const top = this._center.y - this._verticalRadius

        const width = this._horizontalRadius * 2
        const height = this._verticalRadius * 2

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
        this._center = { x: rect.left + rect.width / 2, y: rect.top + rect.height / 2 }
        this._horizontalRadius = rect.width / 2
        this._verticalRadius = rect.height / 2
    }
}

export {
    Ellipse,
}