package org.volgatech.ood.lw8.multigumballmachine.withstate;

public class MultiGumballMachine {
    static final int MAX_QUARTERS_COUNT = 5;

    private State soldOutState;
    private State noQuarterState;
    private State hasQuarterState;
    private State soldState;
    private State maxQuartersState;

    private State state;
    int gumBallsCount;
    int quartersCount = 0;

    public MultiGumballMachine(int gumballsCount) {
        soldOutState = new SoldOutState(this);
        noQuarterState = new NoQuarterState(this);
        hasQuarterState = new HasQuarterState(this);
        soldState = new SoldState(this);
        maxQuartersState = new MaxQuartersState(this);

        this.gumBallsCount = gumballsCount;

        if (gumballsCount > 0) {
            state = noQuarterState;
        } else {
            state = soldOutState;
        }
    }

    public void insertQuarter() {
        state.insertQuarter();
    }

    public void ejectQuarters() {
        state.ejectQuarter();
    }

    public void turnCrank() {
        state.turnCrank();
        state.dispense();
    }

    public void refill(int gumBallsCount) {
        state.refill(gumBallsCount);
    }

    public String toString() {
        StringBuilder result = new StringBuilder();
        result.append("\nMighty Gumball, Inc.");
        result.append("\nJava-enabled Standing Gumball Model #2004\n");
        result.append("Inventory: ").append(gumBallsCount).append(" gumball");
        if (gumBallsCount != 1) {
            result.append("s");
        }
        result.append("Quarters count: ").append(quartersCount);
        result.append("Machine is ").append(state).append("\n");
        return result.toString();
    }

    void addQuarter() {
        quartersCount++;
        System.out.println("Inserting #" + quartersCount + " quarter");
    }

    void returnQuarters() {
        while (quartersCount > 0) {
            returnQuarter();
        }
    }

    void releaseBall() {
        gumBallsCount--;
        quartersCount--;
        System.out.println("A gumball comes rolling out the slot...");
    }

    void refillImpl(int gumBallsCount) {
        this.gumBallsCount = gumBallsCount;
        System.out.println("Refill gumballs: " + gumBallsCount);
    }

    void setState(State state) {
        this.state = state;
    }

    State getSoldOutState() {
        return soldOutState;
    }

    State getNoQuarterState() {
        return noQuarterState;
    }

    State getHasQuarterState() {
        return hasQuarterState;
    }

    State getSoldState() {
        return soldState;
    }

    State getMaxQuartersState() {
        return maxQuartersState;
    }

    private void returnQuarter() {
        quartersCount--;
        System.out.println("Quarter returned");
    }
}
