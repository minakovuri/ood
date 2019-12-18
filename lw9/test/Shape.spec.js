import {Shape} from "../src/model/shapes/Shape";
import {expect} from "chai"

describe('create shape test', () => {
    it('create ellipse', () => {
        const frame = {
            left: 20,
            top: 20,
            width: 20,
            height: 30,
        }

        const ellipse = new Shape(frame, 'ellipse')

        expect(ellipse.getType()).to.eql('ellipse')
        expect(ellipse.getRect()).to.eql(frame)
    })

    it('create rectangle', () => {
        const frame = {
            left: 20,
            top: 20,
            width: 20,
            height: 30,
        }

        const rectangle = new Shape(frame, 'rectangle')

        expect(rectangle.getType()).to.eql('rectangle')
        expect(rectangle.getRect()).to.eql(frame)
    })

    it('create triangle', () => {
        const frame = {
            left: 20,
            top: 20,
            width: 20,
            height: 30,
        }

        const triangle = new Shape(frame, 'triangle')

        expect(triangle.getType()).to.eql('triangle')
        expect(triangle.getRect()).to.eql(frame)
    })
})

describe('set shape frame test', () => {
    it('set shape', () => {
        const frame = {
            left: 20,
            top: 20,
            width: 20,
            height: 30,
        }

        const shape = new Shape(frame, 'rectangle')

        const newFrame = {
            left: 15,
            top: 20,
            width: 10,
            height: 15,
        }
        shape.setRect(newFrame)

        expect(shape.getRect()).to.eql(newFrame)
    })
})