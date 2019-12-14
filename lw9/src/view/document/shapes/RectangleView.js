import {ShapeView} from "./ShapeView.js"

class RectangleView extends ShapeView {
    constructor(rect, id) {
        super(rect, id);
    }

    /**
     * @override
     */
    render() {
        const rect = this.state.rect

        return this.html`
<svg class="shape-wrapper" onmousedown=${this}>
    <rect class="shape" x=${rect.left} y=${rect.top} width=${rect.width} height=${rect.height}></rect>
</svg>`
    }
}

export {
    RectangleView,
}