import {Dispatcher} from "../../common/Dispatcher"
import {Rect} from "../../common/Types"
import {ShapeEvents} from "./Events"
import {generateUUID} from "../../common/generateUUID.js"

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
     * @return {string}
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
        this.dispatch(ShapeEvents.RESIZE)
    }

    /**
     * @abstract
     * @return {string}
     * @private
     */
    _getTypeImpl() {}

    /**
     * @abstract
     * @param {Rect} rect
     * @private
     */
    _setFrameImpl(rect) {}

    /**
     * @abstract
     * @return {Rect}
     * @private
     */
    _getFrameImpl() {}
}

export {
    Shape,
}