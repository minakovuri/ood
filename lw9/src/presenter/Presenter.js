import {AppModel} from "../model/AppModel.js"
import {ShapeFactory} from "./ShapeFactory.js"
import {Rect} from "../common/Types.js"
import {AppView} from "../view/AppView.js"

/**
 * @type {Rect}
 */
const defaultShapeFrame = { left: 100, top: 100, width: 300, height: 400 }

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

        menuView.doOnAddTriangle(() => this._model.insertShape(ShapeFactory.createTriangle(defaultShapeFrame)))
        //menuView.doOnAddRectangle(() => console.log('Add rectangle'))
        //menuView.doOnAddEllipse(() => console.log('Add ellipse'))
    }

    _initModel() {
        this._model.onInsertShape((details) => this._insertShapeHandler(details))
    }

    _insertShapeHandler(details) {
        const shapeId = details.id
        const shape = this._model.getShape(shapeId)

        const shapeType = shape.getType()
        const shapeFrame = shape.getFrame()

        const documentView = this._view.getDocument()
        documentView.addShape(shapeFrame, shapeType)
    }
}

export {
    Presenter,
}