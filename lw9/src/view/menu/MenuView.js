import {InsertView} from "./InsertView.js"
import {hyper} from "hyperhtml"

class MenuView {
    constructor() {
        this._insertView = new InsertView()
    }

    render() {
        return hyper.wire()`
<div class="menu-view">
    <div class="tabs"></div>
    <div class="content">
        ${this._insertView.render()}
    </div>
</div>`
    }
}

export {
    MenuView,
}