import {Dispatcher} from "../../common/Dispatcher"
import {Rect} from "../types/Rect.js"
import {ShapeEvents} from "./Events"
import {generateUUID} from "../../common/generateUUID.js"

/**
 * @typedef {'triangle'|'rectangle'|'ellipse'}
 */
let ShapeType

class Shape extends Dispatcher {
    /**
     * @param {Rect} rect
     * @param {ShapeType} type
     */
    constructor(rect, type) {
        super();

        this._id = generateUUID()
        this._rect = rect
        this._type = type
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
        return this._type
    }

    /**
     * @return {Rect}
     */
    getRect() {
        return this._rect
    }

    /**
     * @param {Rect} rect
     */
    setRect(rect) {
        this._rect = rect
        this.dispatch(ShapeEvents.UPDATE_RECT)
    }
}

export {
    Shape,
    ShapeType,
}