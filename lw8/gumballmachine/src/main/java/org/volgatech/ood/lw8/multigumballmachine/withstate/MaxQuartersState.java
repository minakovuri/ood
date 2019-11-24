package org.volgatech.ood.lw8.multigumballmachine.withstate;

public class MaxQuartersState implements State {
    private MultiGumballMachine gumballMachine;

    MaxQuartersState(MultiGumballMachine gumballMachine) {
        this.gumballMachine = gumballMachine;
    }

    @Override
    public void insertQuarter() {
        System.out.println("Max number of quarters");
    }

    @Override
    public void ejectQuarter() {
        gumballMachine.returnQuarters();
        gumballMachine.setState(gumballMachine.getNoQuarterState());
    }

    @Override
    public void turnCrank() {
        System.out.println("You turned...");
        gumballMachine.setState(gumballMachine.getSoldState());
    }

    @Override
    public void dispense() {
        System.out.println("No gumball dispensed");
    }

    @Override
    public void refill(int gumBallsCount) {
        gumballMachine.refillImpl(gumBallsCount);
    }

    public String toString() {
        return "max quarters";
    }
}
