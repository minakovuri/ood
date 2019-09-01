package test

import (
	"../../duck"
	"../dance"
	"../fly"
	"../quack"
)

func ExampleNewMallardDuck() {
	mallardDuck := duck.NewMallardDuck()

	mallardDuck.Display()
	mallardDuck.Swim()
	
	mallardDuck.PerformQuack()
	mallardDuck.PerformFly()
	mallardDuck.PerformDance()

	// Output: I'm a mallard duck!
	// All ducks can swim!
	// Quack!
	// I can fly!
	// Let's dance waltz!
}

func ExampleModifyMallardDuckBehaviours()  {
	mallardDuck := duck.NewMallardDuck()

	mallardDuck.SetQuackBehaviour(quack.Squeak{})
	mallardDuck.SetFlyBehaviour(fly.FlyNoWay{})
	mallardDuck.SetDanceBehaviour(dance.NotDance{})

	mallardDuck.PerformQuack()
	mallardDuck.PerformFly()
	mallardDuck.PerformDance()

	// Output: Pik-pik!
	// I can't fly...
	// I can't dance...
}
