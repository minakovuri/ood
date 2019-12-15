import {Triangle} from "./shapes/Triangle.js"
import {Rectangle} from "./shapes/Rectangle.js"
import {Ellipse} from "./shapes/Ellipse.js"
import {Rect} from "./types/Rect.js"
import {Shape, ShapeType} from "./shapes/Shape.js"

class ShapeFactory {
    /**
     * @param {Rect} rect
     * @param {ShapeType} type
     * @return {Shape}
     */
    static createShape(rect, type) {
        let shape

        switch (type) {
            case "triangle":
                shape = new Triangle(rect)
                break
            case "ellipse":
                shape = new Ellipse(rect)
                break
            case "rectangle":
                shape = new Rectangle(rect)
                break
            default:
                break
        }

        return shape
    }
}

export {
    ShapeFactory,
}