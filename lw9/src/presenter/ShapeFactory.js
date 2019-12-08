import {Triangle} from "../model/shapes/Triangle.js"
import {Rectangle} from "../model/shapes/Rectangle.js"
import {Ellipse} from "../model/shapes/Ellipse.js"
import {Rect} from "../common/Types.js"
import {Shape} from "../model/shapes/Shape.js"

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