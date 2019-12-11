import {Document} from "./document/Document.js"
import {Shape} from "./shapes/Shape.js"
import {Rect} from "../common/Types.js"

class AppModel {
    constructor() {
        this._document = new Document()
    }

    /**
     * @param {Rect} rect
     */
    insertShape(rect) {
        this._document.insertShape(rect)
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
        this._document.removeShape()
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
}

export {
    AppModel,
}