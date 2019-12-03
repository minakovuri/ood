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
     */
    dispatch(event) {
        this._events[event].forEach((listener) => listener())
    }
}

export {
    Dispatcher,
}