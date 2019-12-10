import {MenuView} from "./menu/MenuView.js"
import {hyper} from "hyperhtml"
import {DocumentView} from "./document/DocumentView.js"

class AppView extends hyper.Component {
    constructor() {
        super()

        this._menuView = new MenuView()
        this._documentView = new DocumentView()
    }

    getMenu() {
        return this._menuView
    }

    getDocument() {
        return this._documentView
    }

    render() {
        return this.html`
${this._menuView}
${this._documentView}
`
    }
}

export {
    AppView,
}