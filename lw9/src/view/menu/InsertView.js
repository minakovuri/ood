import {hyper} from "hyperhtml"
import {Dispatcher} from "../../common/Dispatcher.js"

/**
 * @enum {string}
 */
const InsertViewEvents = {
    ADD_TRIANGLE: 'addTriangle',
    ADD_RECTANGLE: 'addRectangle',
    ADD_ELLIPSE: 'addEllipse',
}

class AddShapeButton extends hyper.Component {
    /**
     * @param {string} label
     * @param {function():void} onClick
     */
    constructor(label, onClick) {
        super();

        this._label = label
        this._onClick = onClick
    }

    render() {
        return this.html`
<div class="add-shape-button" onclick=${this._onClick}>${this._label}</div>`
    }
}

class InsertView extends hyper.Component {
    constructor() {
        super();
        this._eventDispatcher = new Dispatcher()
    }

    /**
     * @param {function():void} handler
     */
    doOnAddTriangle(handler) {
        this._eventDispatcher.addListener(InsertViewEvents.ADD_TRIANGLE, handler)
    }

    /**
     * @param {function():void} handler
     */
    doOnAddRectangle(handler) {
        this._eventDispatcher.addListener(InsertViewEvents.ADD_RECTANGLE, handler)
    }

    /**
     * @param {function():void} handler
     */
    doOnAddEllipse(handler) {
        this._eventDispatcher.addListener(InsertViewEvents.ADD_ELLIPSE, handler)
    }

    render() {
        return this.html`
<div class="insert-view">
    ${ new AddShapeButton('Add triangle', () => this._eventDispatcher.dispatch(InsertViewEvents.ADD_TRIANGLE)) }
    ${ new AddShapeButton('Add rectangle', () => this._eventDispatcher.dispatch(InsertViewEvents.ADD_RECTANGLE)) }
    ${ new AddShapeButton('Add ellipse', () => this._eventDispatcher.dispatch(InsertViewEvents.ADD_ELLIPSE))}
</div>`
    }
}

export {
    InsertView,
}