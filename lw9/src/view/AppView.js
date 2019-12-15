import {MenuView} from "./menu/MenuView.js"
import {hyper} from "hyperhtml"
import {DocumentView} from "./document/DocumentView.js"
import {DocumentEvents} from "./document/Events.js"
import {ViewRect} from "./types/ViewRect.js"

class AppView extends hyper.Component {
    constructor() {
        super()

        this._menuView = new MenuView()
        this._documentView = new DocumentView()
    }

    /**
     * @param {function():void} handler
     */
    onAddTriangle(handler) {
        this._menuView.doOnAddTriangle(handler)
    }

    /**
     * @param {function():void} handler
     */
    onAddRectangle(handler) {
        this._menuView.doOnAddRectangle(handler)
    }

    /**
     * @param {function():void} handler
     */
    onAddEllipse(handler) {
        this._menuView.doOnAddEllipse(handler)
    }

    /**
     * @param {function():void} handler
     */
    onUpdateShapeRect(handler) {
        this._documentView.addListener(DocumentEvents.UPDATE_SHAPE_RECT, handler)
    }

    /**
     * @param {function():void} handler
     */
    onDeleteShape(handler) {
        this._documentView.addListener(DocumentEvents.DELETE_SHAPE, handler)
        this._menuView.doOnDeleteShape(handler)
    }

    /**
     * @param {string} shapeId
     * @param {ViewRect} rect
     * @param {string} shapeType
     */
    insertShape(shapeId, rect, shapeType) {
        this._documentView.addShape(shapeId, rect, shapeType)
    }

    /**
     * @param {string} shapeId
     * @param {ViewRect} rect
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