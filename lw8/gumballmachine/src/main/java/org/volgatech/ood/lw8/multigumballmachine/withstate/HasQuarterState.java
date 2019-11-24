package org.volgatech.ood.lw8.multigumballmachine.withstate;

public class HasQuarterState implements State {
    private MultiGumballMachine gumballMachine;

    HasQuarterState(MultiGumballMachine gumballMachine) {
        this.gumballMachine = gumballMachine;
    }

    @Override
    public void insertQuarter() {
        gumballMachine.addQuarter();
        if (gumballMachine.quartersCount == MultiGumballMachine.MAX_QUARTERS_COUNT) {
            gumballMachine.setState(gumballMachine.getMaxQuartersState());
        }
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
        return "waiting for turn of crank";
    }
}
