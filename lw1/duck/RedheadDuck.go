package duck

import (
	"./dance"
	"./fly"
	"./quack"
	"fmt"
)

type RedheadDuck struct {
	Duck
}

func (d RedheadDuck) Display() {
	fmt.Println("I'm a redhead duck!")
}

func NewRedheadDuck() *RedheadDuck {
	duck := new(RedheadDuck)

	duck.flyBehaviour = fly.GetFlyWithWingsFunc()
	duck.quackBehaviour = quack.Squeak
	duck.danceBehaviour = dance.DanceMinuet

	return duck
}
