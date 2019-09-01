package quack

import "fmt"

type MuteQuack struct{}

func (q MuteQuack) Quack() {
	fmt.Println("I can't quack...")
}
