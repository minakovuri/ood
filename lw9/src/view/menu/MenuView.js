import {InsertView} from "./InsertView.js"
import {hyper} from "hyperhtml"

class MenuView extends hyper.Component {
    constructor() {
        super()
        this._insertView = new InsertView()
    }

    doOnAddTriangle(handler) {
        this._insertView.doOnAddTriangle(handler)
    }

    doOnAddRectangle(handler) {
        this._insertView.doOnAddRectangle(handler)
    }

    doOnAddEllipse(handler) {
        this._insertView.doOnAddEllipse(handler)
    }

    render() {
        return this.html`
<div class="menu-view">
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