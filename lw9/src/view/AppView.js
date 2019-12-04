import {MenuView} from "./menu/MenuView.js"
import {hyper} from "hyperhtml"

class AppView {
    /**
     * @param {Element} menuElement
     */
    static render(menuElement) {
        const menu = new MenuView()

        hyper.bind(menuElement)`
${ menu.render() }`
    }
}

export {
    AppView,
}