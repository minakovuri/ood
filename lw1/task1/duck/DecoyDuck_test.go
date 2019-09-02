package duck

import (
	"./dance"
	"./fly"
	"./quack"
)

func ExampleNewDecoyDuck() {
	decoyDuck := NewDecoyDuck()

	decoyDuck.Display()
	decoyDuck.Swim()

	decoyDuck.PerformQuack()
	decoyDuck.PerformFly()
	decoyDuck.PerformDance()

	// Output: I'm a decoy duck!
	// All ducks can swim!
	// I can't quack...
	// I can't fly...
	// I can't dance...
}

func ExampleModifyDecoyDuckBehaviours() {
	decoyDuck := NewDecoyDuck()

	decoyDuck.SetQuackBehaviour(quack.Squeak{})
	decoyDuck.SetFlyBehaviour(fly.FlyWithWings{})
	decoyDuck.SetDanceBehaviour(dance.DanceWaltz{})

	decoyDuck.PerformQuack()
	decoyDuck.PerformFly()
	decoyDuck.PerformDance()

	// Output: Pik-pik!
	// I can fly!
	// Let's dance waltz!
}
