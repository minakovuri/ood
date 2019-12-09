import {ShapeView} from "./ShapeView.js"
import hyper from "hyperhtml"

class TriangleView extends ShapeView {
    constructor(frame, id) {
        super(frame, id);

        this.state.isFocused = false
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

        /**
         * @param {Event} e
         */
        function onFocusIn(e) {
            e.preventDefault()
            this.setState({
                isFocused: true,
            })
        }

        /**
         * @param {Event} e
         */
        function onFocusOut(e) {
            e.preventDefault()
            this.setState({
                isFocused: false,
            })
        }

        return this.html`
<svg class="shape-frame" onfocusin="${onFocusIn.bind(this)}" onfocusout="${onFocusOut.bind(this)}">
    <polygon class="shape" points="${vertex1.x},${vertex1.y} ${vertex2.x},${vertex2.y} ${vertex3.x},${vertex3.y}"></polygon>
    ${this.state.isFocused ? this._renderFocusedRect() : null}
</svg>`
    }
}

export {
    TriangleView,
}