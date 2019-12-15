import {Rectangle} from "../src/model/shapes/Rectangle.js"
import {expect} from "chai"

describe('rectangle test', () => {
    it('create rectangle and get frame', () => {
        const frame = {
            left: 20,
            top: 20,
            width: 20,
            height: 30,
        }

        const rectangle = new Rectangle(frame)

        expect(rectangle.getRect()).to.eql(frame)
    })

    it('create rectangle and set frame', () => {
        const frame = {
            left: 20,
            top: 20,
            width: 20,
            height: 30,
        }

        const triangle = new Rectangle(frame)

        const newFrame = {
            left: 15,
            top: 20,
            width: 10,
            height: 15,
        }
        triangle.setRect(newFrame)

        expect(triangle.getRect()).to.eql(newFrame)
    })
})