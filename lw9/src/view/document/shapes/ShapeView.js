import {DispatcherComponent} from "../../common/DispatcherComponent.js"
import {Rect} from "../../../common/Types.js"

/** @typedef {'triangle'|'rectangle'|'ellipse'}*/
let ShapeType

class ShapeView extends DispatcherComponent {
    /**
     * @param {Rect} rect
     * @param {string} id
     */
    constructor(rect, id) {
        super();

        /**
         * @type {string}
         * @private
         */
        this._id = id

        this.state.rect = rect
    }

    /**
     * @return {string}
     */
    getId() {
        return this._id
    }

    /**
     * @param {Rect} rect
     */
    setRect(rect) {
        this.setState({
            rect: rect,
        })
    }

    /**
     * @return {Rect}
     */
    getRect() {
        return this.state.rect
    }

    /**
     * @abstract
     */
    render() {}
}

export {
    ShapeType,
    ShapeView,
}