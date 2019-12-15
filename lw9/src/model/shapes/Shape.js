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
    getFrame() {
        return this._getFrameImpl()
    }

    /**
     * @param {Rect} rect
     */
    setFrame(rect) {
        this._setFrameImpl(rect)
        this.dispatch(ShapeEvents.UPDATE_RECT)
    }

    /**
     * @abstract
     * @return {string}
     * @protected
     */
    _getTypeImpl() {}

    /**
     * @abstract
     * @param {Rect} rect
     * @protected
     */
    _setFrameImpl(rect) {}

    /**
     * @abstract
     * @return {Rect}
     * @protected
     */
    _getFrameImpl() {}
}

export {
    Shape,
    ShapeType,
}