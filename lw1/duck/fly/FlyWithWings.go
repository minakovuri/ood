package fly

import "fmt"

func GetFlyWithWingsFunc() func() {
	var flyNumber uint
	return func() {
		flyNumber++
		fmt.Println("I'm flying for", flyNumber, "times!")
	}
}
