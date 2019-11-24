package org.volgatech.ood.lw8.multigumballmachine.withstate;

public interface State {
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();
}
