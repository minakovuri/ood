import {Dispatcher} from "../../common/Dispatcher"
import {Rect} from "../types/Rect.js"
import {ShapeEvents} from "./Events"
import {generateUUID} from "../../common/generateUUID.js"

/**
 * @typedef {'triangle'|'rectangle'|'ellipse'}
 */
let ShapeType

class Shape extends Dispatcher {
    constructor() {
        super();

        this._id = generateUUID()
    }

    /**
     * @return {string}
     */
    getId() {
        return this._id
    }

    /**
     * @return {ShapeType}
     */
    getType() {
        return this._getTypeImpl()
    }

    /**
     * @return {Rect}
     */
    getRect() {
        return this._getRectImpl()
    }

    /**
     * @param {Rect} rect
     */
    setRect(rect) {
        this._setRectImpl(rect)
        this.dispatch(ShapeEvents.UPDATE_RECT)
    }

    /**
     * @abstract
     * @return {ShapeType}
     * @protected
     */
    _getTypeImpl() {}

    /**
     * @abstract
     * @param {Rect} rect
     * @protected
     */
    _setRectImpl(rect) {}

    /**
     * @abstract
     * @return {Rect}
     * @protected
     */
    _getRectImpl() {}
}

export {
    Shape,
    ShapeType,
}