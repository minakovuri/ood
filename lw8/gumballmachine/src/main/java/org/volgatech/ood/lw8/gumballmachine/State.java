package org.volgatech.ood.lw8.gumballmachine;

public interface State {
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();
}
