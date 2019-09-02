package duck

import (
	"./dance"
	"./fly"
	"./quack"
)

func ExampleNewRubberDuck() {
	rubberDuck := NewRubberDuck()

	rubberDuck.Display()
	rubberDuck.Swim()

	rubberDuck.PerformQuack()
	rubberDuck.PerformFly()
	rubberDuck.PerformDance()

	// Output: I'm a rubber duck!
	// All ducks can swim!
	// I can't quack...
	// I can't fly...
	// I can't dance...
}

func ExampleModifyRubberDuckBehaviours() {
	rubberDuck := NewRubberDuck()

	rubberDuck.SetQuackBehaviour(quack.Squeak{})
	rubberDuck.SetFlyBehaviour(fly.FlyWithWings{})
	rubberDuck.SetDanceBehaviour(dance.DanceWaltz{})

	rubberDuck.PerformQuack()
	rubberDuck.PerformFly()
	rubberDuck.PerformDance()

	// Output: Pik-pik!
	// I can fly!
	// Let's dance waltz!
}
