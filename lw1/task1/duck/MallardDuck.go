package duck

import (
	"./dance"
	"./fly"
	"./quack"
	"fmt"
)

type MallardDuck struct {
	Duck
}

func (d MallardDuck) Display()  {
	fmt.Println("I'm a mallard duck!")
}

func NewMallardDuck() *MallardDuck  {
	duck := new(MallardDuck)

	duck.flyBehaviour = fly.FlyWithWings{}
	duck.quackBehaviour = quack.Quack{}
	duck.danceBehaviour = dance.DanceWaltz{}

	return duck
}