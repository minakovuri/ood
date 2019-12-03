import {Dispatcher} from "../../common/Dispatcher"
import {IShape} from "./IShape"
import {Rect} from "../../common/Types"
import {ShapeEvents} from "./Events"

/**
 * @implements IShape
 */
class Shape extends Dispatcher {
    constructor() {
        super();
    }

    getId() {
        return ""
    }

    getFrame() {
        return this._getFrameImpl()
    }

    setFrame(rect) {
        this._setFrameImpl(rect)
        this.dispatch(ShapeEvents.RESIZE)
    }

    /**
     * @param {Rect} rect
     * @private
     */
    _setFrameImpl(rect) {}

    /**
     * @return {Rect}
     * @private
     */
    _getFrameImpl() {}
}

export {
    Shape,
}