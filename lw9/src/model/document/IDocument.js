import {IShape} from "../shapes/IShape"

/**
 * @interface
 */
class IDocument {
    /**
     * @param {IShape} shape
     */
    insertShape(shape) {}

    /**
     * @param {string} shapeId
     * @return {IShape}
     */
    getShape(shapeId) {}

    /**
     * @param {string} shapeId
     */
    removeShape(shapeId) {}
}

export {
    IDocument,
}