package fly

import "fmt"

type FlyWithWings struct {
	flyNumber uint
}

func (f *FlyWithWings) Fly() {
	f.flyNumber++
	fmt.Println("I'm fly for ", f.flyNumber, "times")
}
