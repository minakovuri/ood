import {hyper} from "hyperhtml"
import {Rect} from "../../common/Types.js"

class ShapeView extends hyper.Component {
    /**
     * @param {Rect} frame
     */
    constructor(frame) {
        super();

        /**
         * @protected
         */
        this._frame = frame
    }

    /**
     * @param {Rect} frame
     */
    setFrame(frame) {
        this._frame = frame
    }

    render() {
        return this._renderImpl()
    }

    /**
     * @abstract
     * @private
     */
    _renderImpl() {}
}

export {
    ShapeView,
}