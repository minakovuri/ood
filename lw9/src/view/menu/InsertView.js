import {hyper} from "hyperhtml"
import {Dispatcher} from "../../common/Dispatcher.js"

/**
 * @typedef ('triangle'|'rectangle'|'ellipse')
 */
let ShapeType

class InsertView extends Dispatcher {
    constructor() {
        super();
    }

    render() {
        return hyper.wire()`
<div class="insert-view">
    ${ this._renderAddShapeButton('triangle') }
    ${ this._renderAddShapeButton('rectangle') }
    ${ this._renderAddShapeButton('ellipse') }
</div>`
    }

    /**
     * @param {ShapeType} shapeType
     * @private
     */
    _renderAddShapeButton(shapeType) {
        let buttonLabel
        let onButtonClick

        switch (shapeType) {
            case 'triangle':
                buttonLabel = 'Add triangle'
                onButtonClick = () => console.log('triangle')
                break
            case 'rectangle':
                buttonLabel = 'Add rectangle'
                onButtonClick = () => console.log('rectangle')
                break
            case 'ellipse':
                buttonLabel = 'Add ellipse'
                onButtonClick = () => console.log('ellipse')
                break
            default:
                console.error(`unknown shape type: ${shapeType}`)
                return
        }

        return hyper.wire()`
<div class="add-shape-button" onclick=${onButtonClick}>${buttonLabel}</div>`
    }
}

export {
    InsertView,
}