import {hyper} from "hyperhtml"
import {ShapeView} from "../shapes/ShapeView.js"
import {Rect} from "../../common/Types.js"
import {TriangleView} from "../shapes/TriangleView.js"

/** @typedef {'triangle'|'rectangle'|'ellipse'}*/
let ShapeType

class DocumentView extends hyper.Component{
    constructor() {
        super();

        /**
         * @type {Array<ShapeView>}
         * @private
         */
        this._shapes = []
    }

    /**
     * @param {Rect} frame
     * @param {string} id
     * @param {ShapeType} type
     */
    addShape(frame, id, type) {
        let shape

        switch(type) {
            case "triangle":
                shape = new TriangleView(frame, id)
                break
            case "rectangle":
                break
            case "ellipse":
                break
        }

        this._shapes.push(shape)
        this.render()
    }

    render() {
        return this.html`
<svg width="1200" height="600">
    ${this._shapes.map(shape => shape.render())}
</svg >`
    }
}

export {
    DocumentView,
}