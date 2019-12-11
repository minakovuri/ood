import {AppModel} from "../model/AppModel.js"
import {Rect} from "../common/Types.js"
import {AppView} from "../view/AppView.js"

/**
 * @type {Rect}
 */
const defaultShapeRect = { left: 100, top: 100, width: 300, height: 400 }

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
        const menuView = this._view.getMenu()

        menuView.doOnAddTriangle(() => this._model.insertShape(defaultShapeRect))
        //menuView.doOnAddRectangle(() => console.log('Add rectangle'))
        //menuView.doOnAddEllipse(() => console.log('Add ellipse'))

        this._view.onChangeShapeRect(({ shapeId, newRect }) => {
            this._model.changeShapeRect(shapeId, newRect)
        })
    }

    _initModel() {
        function insertShapeHandler({ shapeId }) {
            const shape = this._model.getShape(shapeId)

            const shapeType = shape.getType()
            const shapeFrame = shape.getFrame()

            const documentView = this._view.getDocument()
            documentView.addShape(shapeFrame, shapeId, shapeType)
        }

        function changeShapeRectHandler({ shapeId }) {
            const shape = this._model.getShape(shapeId)
            const rect  = shape.getFrame()

            this._view.updateShape(shapeId, rect)
        }

        this._model.onInsertShape(insertShapeHandler.bind(this))
        this._model.onChangeShapeRect(changeShapeRectHandler.bind(this))
    }
}

export {
    Presenter,
}