import {ShapeType} from "./ShapeView.js"
import {Rect} from "../../../common/Types.js"
import {TriangleView} from "./TriangleView.js"

class ShapesFactory {
    /**
     * @param {Rect} rect
     * @param {string} id
     * @param {ShapeType} type
     */
    static createShape(rect, id, type) {
        let shape

        switch(type) {
            case "triangle":
                shape = new TriangleView(rect, id)
                break
            case "rectangle":
                break
            case "ellipse":
                break
        }

        return shape
    }
}

export {
    ShapesFactory,
}