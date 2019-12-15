import {AppModel} from "../model/AppModel.js"
import {Rect} from "../model/types/Rect.js"
import {AppView} from "../view/AppView.js"
import {ViewRect} from "../view/types/ViewRect.js"
import {ViewShapeType} from "../view/document/shapes/ShapeType.js"

/**
 * @type {Rect}
 */
const defaultShapeRect = { left: 450, top: 250, width: 400, height: 300 }

class Presenter {
    /**
     * @param {AppView} view
     */
    constructor(view) {
        this._view = view
        this._model = new AppModel()

        this._initView()
        this._initModel()
    }

    _initView() {
        this._view.onAddTriangle(() => this._model.insertShape(defaultShapeRect, 'triangle'))
        this._view.onAddRectangle(() => this._model.insertShape(defaultShapeRect, 'rectangle'))
        this._view.onAddEllipse(() => this._model.insertShape(defaultShapeRect, 'ellipse'))

        this._view.onUpdateShapeRect(({ shapeId, newRect }) => {
            this._model.changeShapeRect(shapeId, newRect)
        })

        this._view.onDeleteShape(() => {
            const selectedShapeId = this._view.getSelectedShapeId()
            this._model.removeShape(selectedShapeId)
        })
    }

    _initModel() {
        function insertShapeHandler({ shapeId }) {
            const shape = this._model.getShape(shapeId)

            const modelShapeType = shape.getType()
            const modelShapeRect = shape.getRect()

            /**
             * @type {ViewShapeType}
             */
            const viewShapeType =  /** @type {ViewShapeType} */ (modelShapeType)

            /**
             * @type {ViewRect}
             */
            const viewShapeRect = /** @type {ViewRect} */ (modelShapeRect)

            this._view.insertShape(shapeId, viewShapeRect, viewShapeType)
        }

        function changeShapeRectHandler({ shapeId }) {
            const shape = this._model.getShape(shapeId)

            const modelShapeRect = shape.getRect()

            /**
             * @type {ViewRect}
             */
            const viewShapeRect = /** @type {ViewRect} */ (modelShapeRect)

            this._view.updateShape(shapeId, viewShapeRect)
        }

        function removeShapeHandler({ shapeId }) {
            this._view.removeShape(shapeId)
        }

        this._model.onInsertShape(insertShapeHandler.bind(this))
        this._model.onChangeShapeRect(changeShapeRectHandler.bind(this))
        this._model.onRemoveShape(removeShapeHandler.bind(this))
    }
}

export {
    Presenter,
}