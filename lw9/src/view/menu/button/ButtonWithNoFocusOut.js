import {Button} from "./Button.js"

class ButtonWithNoFocusOut extends Button {
    /**
     * @param {string} label
     * @param {function():void} onClick
     */
    constructor(label, onClick) {
        super(label, onClick);
    }

    /**
     * @param {MouseEvent} e
     * @private
     */
    onmousedown(e) {
        e.preventDefault()
    }

    /**
     * @override
     */
    render() {
        return this.html`
<div class="button" onmousedown=${this} onclick=${this._onClick}>${this._label}</div>`
    }
}

export {
    ButtonWithNoFocusOut,
}