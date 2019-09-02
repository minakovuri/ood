package duck

import (
	"./dance"
	"./fly"
	"./quack"
	"fmt"
)

type DecoyDuck struct {
	Duck
}

func (d DecoyDuck) Display() {
	fmt.Println("I'm a decoy duck!")
}
func NewDecoyDuck() *DecoyDuck {
	duck := new(DecoyDuck)

	duck.flyBehaviour = fly.FlyNoWay
	duck.quackBehaviour = quack.MuteQuack
	duck.danceBehaviour = dance.NotDance

	return duck
}
