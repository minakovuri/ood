package quack

import "fmt"

type Squeak struct{}

func (q Squeak) Quack() {
	fmt.Println("Pik-pik!")
}
