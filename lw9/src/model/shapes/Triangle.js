import {Shape} from "./Shape"
import {Point} from "../../common/Types"
import {Rect} from "../../common/Types"

class Triangle extends Shape {
    /**
     * @param {Rect} rect
     */
    constructor(rect) {
        super()

        /**
         * @type {Point}
         * @private
         */
        this._vertex1 = { x: rect.left, y: rect.top + rect.height }

        /**
         * @type {Point}
         * @private
         */
        this._vertex2 = { x: rect.left + rect.width / 2, y: rect.top }

        /**
         * @type {Point}
         * @private
         */
        this._vertex3 = { x: rect.left + rect.width, y: rect.top + rect.height }
    }

    /**
     * @override
     * @private
     */
    _getTypeImpl() {
        return 'triangle'
    }

    /**
     * @override
     * @private
     */
    _getFrameImpl() {
        const minX = Math.min(this._vertex1.x, this._vertex2.x, this._vertex3.x)
        const minY = Math.min(this._vertex1.y, this._vertex2.y, this._vertex3.y)

        const maxX = Math.max(this._vertex1.x, this._vertex2.x, this._vertex3.x)
        const maxY = Math.max(this._vertex1.y, this._vertex2.y, this._vertex3.y)

        return {
            left: minX,
            top: minY,
            width: maxX - minX,
            height: maxY - minY,
        }
    }

    /**
     * @override
     * @private
     */
    _setFrameImpl(rect) {
        const currentFrame = this._getFrameImpl()

        /**
         * @param {Point} vertex
         */
        function updateVertex(vertex) {
            const scaleX = (vertex.x - currentFrame.left) / currentFrame.width
            const scaleY = (vertex.y - currentFrame.top) / currentFrame.height

            vertex.x = rect.left + rect.width * scaleX
            vertex.y = rect.top + rect.height * scaleY
        }

        updateVertex(this._vertex1)
        updateVertex(this._vertex2)
        updateVertex(this._vertex3)
    }
}

export {
    Triangle,
}