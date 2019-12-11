import {Triangle} from "./shapes/Triangle.js"
import {Rectangle} from "./shapes/Rectangle.js"
import {Ellipse} from "./shapes/Ellipse.js"
import {Rect} from "../common/Types.js"
import {Shape} from "./shapes/Shape.js"

class ShapeFactory {
    /**
     * @param {Rect} frame
     * @return {Shape}
     */
    static createTriangle(frame) {
        return new Triangle(frame)
    }

    static createRectangle(frame) {

    }

    static createEllipse(frame) {

    }
}

export {
    ShapeFactory,
}