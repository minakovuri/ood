package duck

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
