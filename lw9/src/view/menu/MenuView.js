import {InsertView} from "./InsertView.js"
import {hyper} from "hyperhtml"

class MenuView extends hyper.Component {
    constructor() {
        super()
        this._insertView = new InsertView()
    }

    /**
     * @param {function():void} handler
     */
    doOnAddTriangle(handler) {
        this._insertView.doOnAddTriangle(handler)
    }

    /**
     * @param {function():void} handler
     */
    doOnAddRectangle(handler) {
        this._insertView.doOnAddRectangle(handler)
    }

    /**
     * @param {function():void} handler
     */
    doOnAddEllipse(handler) {
        this._insertView.doOnAddEllipse(handler)
    }

    render() {
        return this.html`
<div class="menu">
    <div class="tabs"></div>
    <div class="content">
        ${this._insertView}
    </div>
</div>`
    }
}

export {
    MenuView,
}