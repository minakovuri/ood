package duck

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
