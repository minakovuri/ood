import {ViewRect} from "../../types/ViewRect.js"
import {TriangleView} from "./TriangleView.js"
import {ShapeView} from "./ShapeView.js"
import {RectangleView} from "./RectangleView.js"
import {EllipseView} from "./EllipseView.js"

/** @typedef {'triangle'|'rectangle'|'ellipse'}*/
let ShapeType

class ShapesFactory {
    /**
     * @param {ViewRect} rect
     * @param {string} id
     * @param {ShapeType} type
     * @return {ShapeView}
     */
    static createShape(rect, id, type) {
        let shape

        switch(type) {
            case "triangle":
                shape = new TriangleView(rect, id)
                break
            case "rectangle":
                shape = new RectangleView(rect, id)
                break
            case "ellipse":
                shape = new EllipseView(rect, id)
                break
        }

        return shape
    }
}

export {
    ShapesFactory,
    ShapeType,
}