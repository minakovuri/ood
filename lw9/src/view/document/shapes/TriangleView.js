import {ShapeView} from "./ShapeView.js"

class TriangleView extends ShapeView {
    constructor(frame, id) {
        super(frame, id);
    }

    /**
     * @override
     */
    render() {
        const rect = this.state.rect

        const vertex1 = { x: rect.left, y: rect.top + rect.height }
        const vertex2 = { x: rect.left + rect.width / 2, y: rect.top }
        const vertex3 = { x: rect.left + rect.width, y: rect.top + rect.height }

        return this.html`
<svg class="shape-wrapper" onmousedown=${this}>
    <polygon class="shape" points="${vertex1.x},${vertex1.y} ${vertex2.x},${vertex2.y} ${vertex3.x},${vertex3.y}"></polygon>
</svg>`
    }
}

export {
    TriangleView,
}