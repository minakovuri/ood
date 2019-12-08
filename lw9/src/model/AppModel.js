import {Document} from "./document/Document.js"
import {Shape} from "./shapes/Shape.js"

class AppModel {
    constructor() {
        this._document = new Document()
    }

    /**
     * @param {Shape} shape
     */
    insertShape(shape) {
        this._document.insertShape(shape)
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
}

export {
    AppModel,
}