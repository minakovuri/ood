import {hyper} from "hyperhtml"
import {Dispatcher} from "../../common/Dispatcher.js"

class DispatcherComponent extends hyper.Component {
    constructor() {
        super();

        /**
         * @type {Dispatcher}
         * @private
         */
        this._dispatcher = new Dispatcher()
    }

    /**
     * @param {string} event
     * @param {function():void} callback
     */
    addListener(event, callback) {
        this._dispatcher.addListener(event, callback)
    }

    /**
     * @param {string} event
     * @param {function():void} callback
     */
    removeListener(event, callback) {
        this._dispatcher.removeListener(event, callback)
    }

    /**
     * @param {string} event
     * @param {Object=} details
     */
    dispatchEvent(event, details) {
        this._dispatcher.dispatch(event, details)
    }
}

export {
    DispatcherComponent,
}