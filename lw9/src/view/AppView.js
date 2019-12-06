import {MenuView} from "./menu/MenuView.js"
import {hyper} from "hyperhtml"

class AppView extends hyper.Component {
    constructor() {
        super()
        this._menuView = new MenuView()
    }

    getMenu() {
        return this._menuView
    }

    render() {
        return this.html`
<div class="menu">
    ${this._menuView}
</div>
<div class="document"></div>`
    }
}

export {
    AppView,
}