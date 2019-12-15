import {ViewRect} from "../../types/ViewRect.js"
import {DispatcherComponent} from "../../common/DispatcherComponent.js"
import {ResizeHandler} from "./ResizeHandler.js"
import {FrameEvents} from "./Events.js"

const MIN_WIDTH = 1
const MIN_HEIGHT = 1

class Frame extends DispatcherComponent {
    /**
     * @param {string} shapeId
     * @param {ViewRect} rect
     */
    constructor(shapeId, rect) {
        super();

        /**
         * @type {string}
         * @private
         */
        this._shapeId = shapeId

        this._topLeftResizeHandler = new ResizeHandler('left-diagonal', ({ x, y }) => {
            const currentRect = this.state.rect

            const widthDiff = currentRect.left - x
            const heightDiff = currentRect.top - y

            const left = x
            const top = y
            const width = currentRect.width + widthDiff
            const height = currentRect.height + heightDiff

            if (width >= MIN_WIDTH && height >= MIN_HEIGHT) {
                this.dispatchEvent(FrameEvents.RESIZE, {left, top, width, height})
            }
        })

        this._topMiddleResizeHandler = new ResizeHandler('vertical', ({ x, y }) => {
            const currentRect = this.state.rect
            const heightDiff = currentRect.top - y

            const left = currentRect.left
            const top = y
            const width = currentRect.width
            const height = currentRect.height + heightDiff

            if (height >= MIN_HEIGHT) {
                this.dispatchEvent(FrameEvents.RESIZE, {left, top, width, height})
            }
        })

        this._topRightResizeHandler = new ResizeHandler('right-diagonal', ({ x, y }) => {
            const currentRect = this.state.rect

            const widthDiff = x - (currentRect.left + currentRect.width)
            const heightDiff = currentRect.top - y

            const left = currentRect.left
            const top = y
            const width = currentRect.width + widthDiff
            const height = currentRect.height + heightDiff

            if (width >= MIN_WIDTH && height >= MIN_HEIGHT) {
                this.dispatchEvent(FrameEvents.RESIZE, {left, top, width, height})
            }
        })

        this._leftMiddleResizeHandler = new ResizeHandler('horizontal', ({ x, y }) => {
            const currentRect = this.state.rect

            const widthDiff = currentRect.left - x

            const left = x
            const top = currentRect.top
            const width = currentRect.width + widthDiff
            const height = currentRect.height

            if (width >= MIN_WIDTH) {
                this.dispatchEvent(FrameEvents.RESIZE, {left, top, width, height})
            }
        })

        this._rightMiddleResizeHandler = new ResizeHandler('horizontal', ({ x, y }) => {
            const currentRect = this.state.rect

            const widthDiff = x - (currentRect.left + currentRect.width)

            const left = currentRect.left
            const top = currentRect.top
            const width = currentRect.width + widthDiff
            const height = currentRect.height

            if (width >= MIN_WIDTH) {
                this.dispatchEvent(FrameEvents.RESIZE, {left, top, width, height})
            }
        })

        this._bottomLeftResizeHandler = new ResizeHandler('right-diagonal', ({ x, y }) => {
            const currentRect = this.state.rect

            const widthDiff = currentRect.left - x
            const heightDiff = y - (currentRect.top + currentRect.height)

            const left = x
            const top = currentRect.top
            const width = currentRect.width + widthDiff
            const height = currentRect.height + heightDiff

            if (width >= MIN_WIDTH && height >= MIN_HEIGHT) {
                this.dispatchEvent(FrameEvents.RESIZE, {left, top, width, height})
            }
        })

        this._bottomMiddleResizeHandler = new ResizeHandler('vertical', ({ x, y }) => {
            const currentRect = this.state.rect

            const heightDiff = y - (currentRect.top + currentRect.height)

            const left = currentRect.left
            const top = currentRect.top
            const width = currentRect.width
            const height = currentRect.height + heightDiff

            if (height >= MIN_HEIGHT) {
                this.dispatchEvent(FrameEvents.RESIZE, {left, top, width, height})
            }
        })

        this._bottomRightResizeHandler = new ResizeHandler('left-diagonal', ({ x, y }) => {
            const currentRect = this.state.rect

            const widthDiff = x - (currentRect.left + currentRect.width)
            const heightDiff = y - (currentRect.top + currentRect.height)

            const left = currentRect.left
            const top = currentRect.top
            const width = currentRect.width + widthDiff
            const height = currentRect.height + heightDiff

            if (width >= MIN_WIDTH && height >= MIN_HEIGHT) {
                this.dispatchEvent(FrameEvents.RESIZE, {left, top, width, height})
            }
        })

        this.state.rect = rect
        this.state.enable = false
    }

    /**
     * @return {string}
     */
    getShapeId() {
        return this._shapeId
    }

    /**
     * @param {ViewRect} rect
     */
    setRect(rect) {
        const newState = {
            shapeId: this.state.shapeId,
            rect: rect,
            enable: this.state.enable,
        }
        this.setState(newState)
    }

    /**
     * @param {boolean} enable
     */
    setEnabled(enable) {
        const newState = {
            shapeId: this.state.shapeId,
            rect: this.state.rect,
            enable: enable,
        }
        this.setState(newState)
    }

    /**
     * @return {boolean}
     */
    getEnabled() {
        return this.state.enable
    }

    render() {
        const rect = this.state.rect

        const topLeft = { x: rect.left, y: rect.top }
        const topMiddle = { x: rect.left + rect.width / 2, y: rect.top }
        const topRight = { x: rect.left + rect.width, y: rect.top }

        const leftMiddle = { x: rect.left, y: rect.top + rect.height / 2 }
        const rightMiddle = { x: rect.left + rect.width, y: rect.top + rect.height / 2 }

        const bottomLeft = { x: rect.left, y: rect.top + rect.height }
        const bottomMiddle = { x: rect.left + rect.width / 2, y: rect.top + rect.height }
        const bottomRight = { x: rect.left + rect.width, y: rect.top + rect.height }

        this._topLeftResizeHandler.update(topLeft)
        this._topMiddleResizeHandler.update(topMiddle)
        this._topRightResizeHandler.update(topRight)

        this._leftMiddleResizeHandler.update(leftMiddle)
        this._rightMiddleResizeHandler.update(rightMiddle)

        this._bottomLeftResizeHandler.update(bottomLeft)
        this._bottomMiddleResizeHandler.update(bottomMiddle)
        this._bottomRightResizeHandler.update(bottomRight)

        const style = {
            display: this.state.enable ? 'block' : 'none'
        }

        return this.html`
<svg class="frame" style=${ style }>
    <line x1="${topLeft.x}" y1="${topLeft.y}" x2="${bottomLeft.x}" y2="${bottomLeft.y}" class="rect-border"></line>
    <line x1="${topLeft.x}" y1="${topLeft.y}" x2="${topRight.x}" y2="${topRight.y}" class="rect-border"></line>
    <line x1="${topRight.x}" y1="${topRight.y}" x2="${bottomRight.x}" y2="${bottomRight.y}" class="rect-border"></line>
    <line x1="${bottomRight.x}" y1="${bottomRight.y}" x2="${bottomLeft.x}" y2="${bottomLeft.y}" class="rect-border"></line>
    ${ this._topLeftResizeHandler }
    ${ this._topMiddleResizeHandler }
    ${ this._topRightResizeHandler }
    ${ this._rightMiddleResizeHandler }
    ${ this._bottomRightResizeHandler }
    ${ this._bottomMiddleResizeHandler }
    ${ this._bottomLeftResizeHandler }
    ${ this._leftMiddleResizeHandler }
</svg>`
    }
}

export {
    Frame,
}