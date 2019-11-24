package org.volgatech.ood.lw8.multigumballmachine.naive;

public class MultiGumballMachine {
    private static final int MAX_QUARTERS_COUNT = 5;

    private final static int SOLD_OUT = 0;
    private final static int NO_QUARTER = 1;
    private final static int HAS_QUARTER = 2;
    private final static int SOLD = 3;

    private int state = SOLD_OUT;
    private int gumBallsCount;
    private int quartersCount = 0;

    public MultiGumballMachine(int gumballsCount) {
        this.gumBallsCount = gumballsCount;
        if (gumballsCount > 0) {
            state = NO_QUARTER;
        }
    }

    public void insertQuarter() {
        switch (state) {
            case HAS_QUARTER:
                addQuarter();
                break;
            case NO_QUARTER:
                addQuarter();
                state = HAS_QUARTER;
                break;
            case SOLD_OUT:
                System.out.println("You can't insert a quarter, the machine is sold out");
                break;
            case SOLD:
                System.out.println("Please wait, we're already giving you a gumball");
                break;
        }
    }

    public void ejectQuarter() {
        switch (state) {
            case HAS_QUARTER:
                returnQuarters();
                break;
            case NO_QUARTER:
                System.out.println("You haven't inserted a quarter");
                break;
            case SOLD:
                System.out.println("Sorry, you already turned the crank");
                break;
            case SOLD_OUT:
                if (quartersCount > 0) {
                    returnQuarters();
                } else {
                    System.out.println("You can't eject, you haven't inserted a quarter yet");
                }
                break;
        }
    }

    public void turnCrank() {
        switch (state) {
            case SOLD:
                System.out.println("Turning twice doesn't get you another gumball!");
                break;
            case NO_QUARTER:
                System.out.println("You turned, but there's no quarter");
                break;
            case SOLD_OUT:
                System.out.println("You turned, but there are no gumballs");
                break;
            case HAS_QUARTER:
                System.out.println("You turned...");
                state = SOLD;
                dispense();
                break;
        }
    }

    public void refill(int numGumBalls) {
        this.gumBallsCount = numGumBalls;
        state = quartersCount > 0 ? HAS_QUARTER : NO_QUARTER;
        System.out.println("Refill gum balls with " + numGumBalls + " count");
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
        result.append("\nMachine is ");
        switch (state) {
            case SOLD_OUT:
                result.append("sold out");
                break;
            case NO_QUARTER:
                result.append("waiting for quarter");
                break;
            case HAS_QUARTER:
                result.append("waiting for turn of crank");
                break;
            case SOLD:
                result.append("delivering a gumball");
                break;
        }
        result.append("\n");
        return result.toString();
    }

    private void dispense() {
        switch (state) {
            case SOLD:
                System.out.println("A gumball comes rolling out the slot...");
                quartersCount--;
                returnGumBall();
                break;
            case NO_QUARTER:
                System.out.println("You need to pay first");
                break;
            case SOLD_OUT:
            case HAS_QUARTER:
                System.out.println("No gumball dispensed");
                break;
        }
    }

    private void addQuarter() {
        if (quartersCount < MAX_QUARTERS_COUNT) {
            quartersCount++;
            System.out.println("Inserting #" + quartersCount + " quarter");
        } else {
            System.out.println("Max number of quarters");
        }
    }

    private void returnQuarters() {
        while (quartersCount > 0) {
            returnQuarter();
        }
        state = NO_QUARTER;
    }

    private void returnQuarter() {
        quartersCount--;
        System.out.println("Quarter returned");
    }

    private void returnGumBall() {
        gumBallsCount--;

        if (gumBallsCount == 0) {
            System.out.println("Oops, out of gumballs!");
            state = SOLD_OUT;
        } else if (quartersCount > 0){
            state = HAS_QUARTER;
        } else {
            state = NO_QUARTER;
        }
    }
}
