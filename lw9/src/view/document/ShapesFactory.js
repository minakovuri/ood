import {ShapeType} from "./shapes/ShapeView.js"
import {Rect} from "../../common/Types.js"
import {TriangleView} from "./shapes/TriangleView.js"
import {ShapeView} from "./shapes/ShapeView.js"
import {RectangleView} from "./shapes/RectangleView.js"
import {EllipseView} from "./shapes/EllipseView.js"

class ShapesFactory {
    /**
     * @param {Rect} rect
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
}