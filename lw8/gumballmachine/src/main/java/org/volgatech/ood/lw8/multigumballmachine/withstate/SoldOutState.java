package org.volgatech.ood.lw8.multigumballmachine.withstate;

public class SoldOutState implements State {
    private MultiGumballMachine gumballMachine;

    SoldOutState(MultiGumballMachine gumballMachine) {
        this.gumballMachine = gumballMachine;
    }

    @Override
    public void insertQuarter() {
        System.out.println("You can't insert a quarter, the machine is sold out");
    }

    @Override
    public void ejectQuarter() {
        if (gumballMachine.quartersCount > 0) {
            gumballMachine.returnQuarters();
        } else {
            System.out.println("You can't eject, you haven't inserted a quarter yet");
        }
    }

    @Override
    public void turnCrank() {
        System.out.println("You turned, but there are no gumballs");
    }

    @Override
    public void dispense() {
        System.out.println("No gumball dispensed");
    }

    public String toString() {
        return "sold out";
    }
}
