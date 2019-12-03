import {Rect} from "../../common/Types"

/**
 * @interface
 */
class IShape {
    /**
     * @return string
     */
    getId() {}

    /**
     * @return Rect
     */
    getFrame() {}

    /**
     * @param {Rect} rect
     */
    setFrame(rect) {}
}

export {
    IShape,
}