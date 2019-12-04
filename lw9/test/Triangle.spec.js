import {Triangle} from "../src/model/shapes/Triangle"
import {expect} from "chai"

describe("triangle test", () => {
    it("create triangle and get frame", () => {
        const triangle = new Triangle({ x: 30, y: 20 }, { x: 20, y: 40 }, { x: 40, y: 50 })

        const expectedRect = {
            left: 20,
            top: 20,
            width: 20,
            height: 30,
        }

        expect(triangle.getFrame()).to.eql(expectedRect)
    })

    it('create triangle and set frame', () => {
        const triangle = new Triangle({ x: 30, y: 20 }, { x: 20, y: 40 }, { x: 40, y: 50 })

        const newFrame = {
            left: 15,
            top: 20,
            width: 10,
            height: 15,
        }
        triangle.setFrame(newFrame)

        expect(triangle.getFrame()).to.eql(newFrame)
    })
})