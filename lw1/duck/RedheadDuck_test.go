package duck

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
	// I'm flying for 1 times!
	// Let's dance minuet!
}
