import {ShapeManagementView} from "./shapeManagement/ShapeManagementView.js"
import {hyper} from "hyperhtml"

class MenuView extends hyper.Component {
    constructor() {
        super()
        this._shapeManagementView = new ShapeManagementView()
    }

    /**
     * @param {function():void} handler
     */
    doOnAddTriangle(handler) {
        this._shapeManagementView.doOnAddTriangle(handler)
    }

    /**
     * @param {function():void} handler
     */
    doOnAddRectangle(handler) {
        this._shapeManagementView.doOnAddRectangle(handler)
    }

    /**
     * @param {function():void} handler
     */
    doOnAddEllipse(handler) {
        this._shapeManagementView.doOnAddEllipse(handler)
    }

    /**
     * @param {function():void} handler
     */
    doOnDeleteShape(handler) {
        this._shapeManagementView.doOnDeleteShape(handler)
    }

    render() {
        return this.html`
<div class="menu">
    ${this._shapeManagementView}
</div>`
    }
}

export {
    MenuView,
}