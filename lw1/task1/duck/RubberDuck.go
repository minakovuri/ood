package duck

import (
	"./dance"
	"./fly"
	"./quack"
	"fmt"
)

type RubberDuck struct {
	Duck
}

func (d RubberDuck) Display()  {
	fmt.Println("I'm a rubber duck!")
}

func NewRubberDuck() *RubberDuck {
	duck := new(RubberDuck)

	duck.flyBehaviour = fly.FlyNoWay{}
	duck.quackBehaviour = quack.MuteQuack{}
	duck.danceBehaviour = dance.NotDance{}

	return duck
}
