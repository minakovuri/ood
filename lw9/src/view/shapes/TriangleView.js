import {ShapeView} from "./ShapeView.js"

class TriangleView extends ShapeView {
    constructor(frame) {
        super(frame);
    }

    /**
     * @override
     * @private
     */
    _renderImpl() {
        const frame = this._frame

        const vertex1 = { x: frame.left, y: frame.top + frame.height }
        const vertex2 = { x: frame.left + frame.width / 2, y: frame.top }
        const vertex3 = { x: frame.left + frame.width, y: frame.top + frame.height }

        return this.html`
<svg>
    <polygon class="shape" points="${vertex1.x},${vertex1.y} ${vertex2.x},${vertex2.y} ${vertex3.x},${vertex3.y}"></polygon>
</svg>`
    }
}

export {
    TriangleView,
}