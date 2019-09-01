package main

import (
	"./duck"
	"./duck/fly"
)

func main() {
	duck := duck.NewMallardDuck()

	duck.PerformFly()
	duck.PerformFly()

	duck.SetFlyBehaviour(&fly.FlyNoWay{})

	duck.PerformFly()

	duck.SetFlyBehaviour(&fly.FlyWithWings{})

	duck.PerformFly()
	duck.PerformFly()
}
