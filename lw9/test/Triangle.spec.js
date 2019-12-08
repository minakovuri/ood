import {Triangle} from "../src/model/shapes/Triangle"
import {expect} from "chai"

describe("triangle test", () => {
    it("create triangle and get frame", () => {
        const frame = {
            left: 20,
            top: 20,
            width: 20,
            height: 30,
        }

        const triangle = new Triangle(frame)

        expect(triangle.getFrame()).to.eql(frame)
    })

    it('create triangle and set frame', () => {
        const frame = {
            left: 20,
            top: 20,
            width: 20,
            height: 30,
        }

        const triangle = new Triangle(frame)

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