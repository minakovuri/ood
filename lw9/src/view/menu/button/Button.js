import {hyper} from "hyperhtml"

class Button extends hyper.Component {
    /**
     * @param {string} label
     * @param {function():void} onClick
     */
    constructor(label, onClick) {
        super();

        /**
         * @type {string}
         * @protected
         */
        this._label = label

        /**
         * @type {function(): void}
         * @protected
         */
        this._onClick = onClick
    }

    render() {
        return this.html`
<div class="button" onclick=${this._onClick}>${this._label}</div>`
    }
}

export {
    Button,
}