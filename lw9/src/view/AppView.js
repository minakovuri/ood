import {MenuView} from "./menu/MenuView.js"
import {hyper} from "hyperhtml"
import {DocumentView} from "./document/DocumentView.js"
import {DocumentEvents} from "./document/Events.js"
import {Rect} from "../common/Types.js"

class AppView extends hyper.Component {
    constructor() {
        super()

        this._menuView = new MenuView()
        this._documentView = new DocumentView()
    }

    getMenu() {
        return this._menuView
    }

    /**
     * @param {function():void} handler
     */
    onChangeShapeRect(handler) {
        this._documentView.addListener(DocumentEvents.CHANGE_RECT, handler)
    }

    /**
     * @param {function():void} handler
     */
    onDeleteShape(handler) {
        this._documentView.addListener(DocumentEvents.DELETE_SHAPE, handler)
    }

    /**
     * @param {string} shapeId
     * @param {Rect} rect
     * @param {string} shapeType
     */
    insertShape(shapeId, rect, shapeType) {
        this._documentView.addShape(shapeId, rect, shapeType)
    }

    /**
     * @param {string} shapeId
     * @param {Rect} rect
     */
    updateShape(shapeId, rect) {
        this._documentView.updateShape(shapeId, rect)
    }

    /**
     * @param {string} shapeId
     */
    removeShape(shapeId) {
        this._documentView.removeShape(shapeId)
    }

    /**
     * @return {?string}
     */
    getSelectedShapeId() {
        return this._documentView.getSelectedShapeId()
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