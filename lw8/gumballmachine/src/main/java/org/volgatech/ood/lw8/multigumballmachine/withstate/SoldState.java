package org.volgatech.ood.lw8.multigumballmachine.withstate;

public class SoldState implements State {
    private MultiGumballMachine gumballMachine;

    SoldState(MultiGumballMachine gumballMachine) {
        this.gumballMachine = gumballMachine;
    }

    @Override
    public void insertQuarter() {
        System.out.println("Please wait, we're already giving you a gumball");
    }

    @Override
    public void ejectQuarter() {
        System.out.println("Sorry, you already turned the crank");
    }

    @Override
    public void turnCrank() {
        System.out.println("Turning twice doesn't get you another gumball!");
    }

    @Override
    public void dispense() {
        gumballMachine.releaseBall();
        if (gumballMachine.gumBallsCount > 0) {
            State newState = gumballMachine.getHasQuarterState();
            gumballMachine.setState(newState);
        } else {
            System.out.println("Oops, out of gumballs!");
            gumballMachine.setState(gumballMachine.getSoldOutState());
        }
    }

    @Override
    public void refill(int gumBallsCount) {
        System.out.println("cannot refill while giving a gumball");
    }

    public String toString() {
        return "delivering a gumball";
    }
}
