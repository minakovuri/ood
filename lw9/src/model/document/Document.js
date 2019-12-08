import {DocumentEvents} from "./Events.js"
import {Dispatcher} from "../../common/Dispatcher.js"
import {Shape} from "../shapes/Shape.js"

class Document {
    constructor() {
        this._dispatcher = new Dispatcher()

        /**
         * @type {Map<string, Shape>}
         * @private
         */
        this._shapes = new Map()
    }

    /**
     * @param {string} shapeId
     * @return {Shape}
     */
    getShape(shapeId) {
        const shape = this._shapes.get(shapeId)
        if (!shape) {
            throw new Error(`shape with id ${shapeId} is not in document`)
        }
        return shape
    }

    /**
     * @param {Shape} shape
     */
    insertShape(shape) {
        const shapeId = shape.getId()

        if (this._shapes.has(shapeId))
        {
            throw new Error(`shape with id ${shapeId} is already has in document`)
        }

        this._shapes.set(shapeId, shape)

        this._dispatcher.dispatch(DocumentEvents.ADD_SHAPE, {
            'id': shapeId,
        })
    }

    removeShape(shapeId) {
    }

    /**
     * @param {function():void} handler
     */
    onInsertShape(handler) {
        this._dispatcher.addListener(DocumentEvents.ADD_SHAPE, handler)
    }
}

export {
    Document
}