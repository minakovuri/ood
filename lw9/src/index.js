import {AppView} from "./view/AppView.js"

const DOM_DOCUMENT_ELEMENT_ID = 'document'
const DOM_MENU_ELEMENT_ID = 'menu'

window.onload = () => {
    const domDocumentElement = document.getElementById(DOM_DOCUMENT_ELEMENT_ID)
    const domMenuElement = document.getElementById(DOM_MENU_ELEMENT_ID)

    AppView.render(domMenuElement)
}