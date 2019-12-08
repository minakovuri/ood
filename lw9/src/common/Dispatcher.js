class Dispatcher {
    constructor() {
        /**
         * @type {Object<string, Array<function():void>>}
         * @private
         */
        this._events = {}
    }

    /**
     * @param {string} event
     * @param {function():void} callback
     */
    addListener(event, callback) {
        if (!this._events[event]) {
            this._events[event] = []
        }
        this._events[event].push(callback)
    }

    /**
     * @param {string} event
     * @param {function():void} callback
     */
    removeListener(event, callback) {
        this._events[event].filter(listener => listener === callback)
    }

    /**
     * @param {string} event
     * @param {Object=} details
     */
    dispatch(event, details) {
        if (this._events[event] && this._events[event].length) {
            this._events[event].forEach((listener) => listener(details))
        }
    }
}

export {
    Dispatcher,
}