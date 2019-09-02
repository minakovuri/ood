package duck

func ExampleNewMallardDuck() {
	mallardDuck := NewMallardDuck()

	mallardDuck.Display()
	mallardDuck.Swim()

	mallardDuck.PerformQuack()
	mallardDuck.PerformFly()
	mallardDuck.PerformDance()

	// Output: I'm a mallard duck!
	// All ducks can swim!
	// Quack!
	// I'm flying for 1 times!
	// Let's dance waltz!
}
