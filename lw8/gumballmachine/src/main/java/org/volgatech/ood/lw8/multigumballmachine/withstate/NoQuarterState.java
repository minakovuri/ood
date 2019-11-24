package org.volgatech.ood.lw8.multigumballmachine.withstate;

public class NoQuarterState implements State {
    private MultiGumballMachine gumballMachine;

    NoQuarterState(MultiGumballMachine gumballMachine) {
        this.gumballMachine = gumballMachine;
    }

    @Override
    public void insertQuarter() {
        gumballMachine.addQuarter();
        gumballMachine.setState(gumballMachine.getHasQuarterState());
    }

    @Override
    public void ejectQuarter() {
        System.out.println("You haven't inserted a quarter");
    }

    @Override
    public void turnCrank() {
        System.out.println("You turned, but there's no quarter");
    }

    @Override
    public void dispense() {
        System.out.println("You need to pay first");
    }

    @Override
    public void refill(int gumBallsCount) {
        gumballMachine.refillImpl(gumBallsCount);
    }

    public String toStrings() {
        return "waiting for quarter";
    }
}
