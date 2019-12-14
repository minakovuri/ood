import {DocumentEvents} from "./Events.js"
import {Dispatcher} from "../../common/Dispatcher.js"
import {Shape} from "../shapes/Shape.js"
import {Rect} from "../../common/Types.js"
import {ShapeFactory} from "../ShapeFactory.js"
import {ShapeEvents} from "../shapes/Events.js"

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
     * @param {Rect} rect
     */
    insertShape(rect) {
        const shape = ShapeFactory.createTriangle(rect)

        const shapeId = shape.getId()

        shape.addListener(ShapeEvents.CHANGE_RECT, () => {
            this._dispatcher.dispatch(DocumentEvents.CHANGE_SHAPE_RECT, {
                shapeId,
            })
        })

        this._shapes.set(shapeId, shape)

        this._dispatcher.dispatch(DocumentEvents.ADD_SHAPE, {
            shapeId,
        })
    }

    /**
     * @param {string} shapeId
     * @param {Rect} rect
     */
    changeShapeRect(shapeId, rect) {
        const shape = this.getShape(shapeId)
        shape.setFrame(rect)
    }

    /**
     * @param {string} shapeId
     */
    removeShape(shapeId) {
        if (this._shapes.delete(shapeId)) {
            this._dispatcher.dispatch(DocumentEvents.REMOVE_SHAPE, {
                shapeId,
            })
        }
    }

    /**
     * @param {function():void} handler
     */
    onInsertShape(handler) {
        this._dispatcher.addListener(DocumentEvents.ADD_SHAPE, handler)
    }

    /**
     * @param {function():void} handler
     */
    onChangeShapeRect(handler) {
        this._dispatcher.addListener(DocumentEvents.CHANGE_SHAPE_RECT, handler)
    }

    /**
     * @param {function():void} handler
     */
    onRemoveShape(handler) {
        this._dispatcher.addListener(DocumentEvents.REMOVE_SHAPE, handler)
    }
}

export {
    Document
}