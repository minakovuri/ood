import {Ellipse} from "../src/model/shapes/Ellipse.js"
import {expect} from "chai"

describe('ellipse test', () => {
    it('create ellipse and get frame', () => {
        const frame = {
            left: 20,
            top: 20,
            width: 20,
            height: 30,
        }

        const triangle = new Ellipse(frame)

        expect(triangle.getRect()).to.eql(frame)
    })

    it('create ellipse and set frame', () => {
        const frame = {
            left: 20,
            top: 20,
            width: 20,
            height: 30,
        }

        const triangle = new Ellipse(frame)

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