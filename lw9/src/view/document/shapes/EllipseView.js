import {ShapeView} from "./ShapeView.js"

class EllipseView extends ShapeView{
    constructor(rect, id) {
        super(rect, id);
    }

    /**
     * @override
     */
    render() {
        const rect = this.state.rect

        const horizontalRadius = rect.width / 2
        const verticalRadius = rect.height / 2

        const center = {
            x: rect.left + horizontalRadius,
            y: rect.top + verticalRadius,
        }

        return this.html`
<svg class="shape-wrapper" onmousedown=${this}>
    <ellipse class="shape" rx=${horizontalRadius} ry=${verticalRadius} cx=${center.x} cy=${center.y}></ellipse>
</svg>`
    }
}

export {
    EllipseView,
}