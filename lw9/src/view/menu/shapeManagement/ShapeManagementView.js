import {hyper} from "hyperhtml"
import {Dispatcher} from "../../../common/Dispatcher.js"
import {ButtonWithNoFocusOut} from "../button/ButtonWithNoFocusOut.js"
import {Button} from "../button/Button.js"
import {ShapeManagementEvents} from "./Events.js"

class ShapeManagementView extends hyper.Component {
    constructor() {
        super();
        this._eventDispatcher = new Dispatcher()
    }

    /**
     * @param {function():void} handler
     */
    doOnAddTriangle(handler) {
        this._eventDispatcher.addListener(ShapeManagementEvents.ADD_TRIANGLE, handler)
    }

    /**
     * @param {function():void} handler
     */
    doOnAddRectangle(handler) {
        this._eventDispatcher.addListener(ShapeManagementEvents.ADD_RECTANGLE, handler)
    }

    /**
     * @param {function():void} handler
     */
    doOnAddEllipse(handler) {
        this._eventDispatcher.addListener(ShapeManagementEvents.ADD_ELLIPSE, handler)
    }

    /**
     * @param {function():void} handler
     */
    doOnDeleteShape(handler) {
        this._eventDispatcher.addListener(ShapeManagementEvents.DELETE_SHAPE, handler)
    }

    render() {
        return this.html`
<div class="shape-management">
    ${ new Button('Add triangle', () => this._eventDispatcher.dispatch(ShapeManagementEvents.ADD_TRIANGLE)) }
    ${ new Button('Add rectangle', () => this._eventDispatcher.dispatch(ShapeManagementEvents.ADD_RECTANGLE)) }
    ${ new Button('Add ellipse', () => this._eventDispatcher.dispatch(ShapeManagementEvents.ADD_ELLIPSE)) }
    ${ new ButtonWithNoFocusOut('Delete', () => this._eventDispatcher.dispatch(ShapeManagementEvents.DELETE_SHAPE)) }
</div>`
    }
}

export {
    ShapeManagementView,
}