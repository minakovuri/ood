package dance

import "fmt"

type NotDance struct {}

func (d NotDance) Dance() {
	fmt.Println("I can't dance...")
}
