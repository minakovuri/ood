import {Document} from "./document/Document.js"
import {Shape, ShapeType} from "./shapes/Shape.js"
import {Rect} from "../common/Types.js"

class AppModel {
    constructor() {
        this._document = new Document()
    }

    /**
     * @param {Rect} rect
     * @param {ShapeType} type
     */
    insertShape(rect, type) {
        this._document.insertShape(rect, type)
    }

    /**
     * @param {string} shapeId
     * @param {Rect} rect
     */
    changeShapeRect(shapeId, rect) {
        this._document.changeShapeRect(shapeId, rect)
    }

    /**
     * @param {string} shapeId
     * @return {Shape}
     */
    getShape(shapeId) {
        return this._document.getShape(shapeId)
    }

    /**
     * @param {string} shapeId
     */
    removeShape(shapeId) {
        this._document.removeShape(shapeId)
    }

    /**
     * @param {function():void} handler
     */
    onInsertShape(handler) {
        this._document.onInsertShape(handler)
    }

    /**
     * @param {function():void} handler
     */
    onChangeShapeRect(handler) {
        this._document.onChangeShapeRect(handler)
    }

    /**
     * @param {function():void} handler
     */
    onRemoveShape(handler) {
        this._document.onRemoveShape(handler)
    }
}

export {
    AppModel,
}