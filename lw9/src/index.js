import {AppView} from "./view/AppView.js"
import {hyper} from "hyperhtml"
import {Presenter} from "./presenter/Presenter.js"

window.onload = () => {
    const rootElement = document.getElementById('root')

    const view = new AppView()

    hyper(rootElement)
        `${view}`

    new Presenter(view)
}