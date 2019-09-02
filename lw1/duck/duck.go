package duck

import (
	"./dance"
	"./fly"
	"./quack"
	"fmt"
)

type Duck struct {
	flyBehaviour   fly.FlyBehaviour
	quackBehaviour quack.QuackBehaviour
	danceBehaviour dance.DanceBehaviour
}

func (d Duck) Swim() {
	fmt.Println("All ducks can swim!")
}

func (d Duck) Display() {
	fmt.Println("I'm a default duck!")
}

func (d Duck) PerformQuack() {
	d.quackBehaviour()
}

func (d Duck) PerformFly() {
	d.flyBehaviour()
}

func (d Duck) PerformDance() {
	d.danceBehaviour()
}

func (d *Duck) SetFlyBehaviour(behaviour fly.FlyBehaviour) {
	d.flyBehaviour = behaviour
}

func (d *Duck) SetQuackBehaviour(behaviour quack.QuackBehaviour) {
	d.quackBehaviour = behaviour
}

func (d *Duck) SetDanceBehaviour(behaviour dance.DanceBehaviour) {
	d.danceBehaviour = behaviour
}
