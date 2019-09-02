package duck

import (
	"./dance"
	"./fly"
	"./quack"
)

func ExampleNewRedheadDuck() {
	redHeadDuck := NewRedheadDuck()

	redHeadDuck.Display()
	redHeadDuck.Swim()

	redHeadDuck.PerformQuack()
	redHeadDuck.PerformFly()
	redHeadDuck.PerformDance()

	// Output: I'm a redhead duck!
	// All ducks can swim!
	// Quack!
	// I can fly!
	// Let's dance minuet!
}

func ExampleModifyRedheadDuckBehaviours() {
	redheadDuck := NewRedheadDuck()

	redheadDuck.SetQuackBehaviour(quack.Squeak{})
	redheadDuck.SetFlyBehaviour(fly.FlyNoWay{})
	redheadDuck.SetDanceBehaviour(dance.NotDance{})

	redheadDuck.PerformQuack()
	redheadDuck.PerformFly()
	redheadDuck.PerformDance()

	// Output: Pik-pik!
	// I can't fly...
	// I can't dance...
}
