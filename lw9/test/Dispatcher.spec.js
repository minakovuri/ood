import {Dispatcher} from "../src/common/Dispatcher"
import {expect} from 'chai'

describe('dispatcher test', () => {
    it('add event listener', () => {
        const dispatcher = new Dispatcher()
        const event = 'inc'
        let i = 0

        dispatcher.addListener(event, () => {
            i++
        })

        dispatcher.dispatch(event)
        expect(i).equal(1)

        dispatcher.dispatch(event)
        expect(i).equal(2)
    })

    it('remove event listener ', () => {
        const dispatcher = new Dispatcher()
        const event = 'inc'
        let i = 0

        const callback = () => {
            i++
        }

        dispatcher.addListener(event, callback)

        dispatcher.dispatch(event)
        expect(i).equal(1)

        dispatcher.removeListener(event, callback)
        expect(i).equal(1)
    })

    it('dispatch event with no listeners', () => {
        const dispatcher = new Dispatcher()
        const event = 'inc'

        dispatcher.dispatch(event)
    })
})