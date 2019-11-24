package org.volgatech.ood.lw8.gumballmachine;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Nested;
import org.junit.jupiter.api.Test;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

import static org.junit.jupiter.api.Assertions.*;

class GumballMachineTest {
    private ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
    private final PrintStream old = System.out;
    private GumballMachine gumballMachine;

    @BeforeEach
    void setUp() {
        PrintStream printStream = new PrintStream(outputStream);
        System.setOut(printStream);

        gumballMachine = new GumballMachine(5);
    }

    @AfterEach
    void tearDown() {
        System.out.flush();
        System.setOut(old);
    }

    @Nested
    class NoQuarterStateTests {
        @Test
        void insertQuarter() {
            gumballMachine.insertQuarter();
            assertEquals("You inserted a quarter\n", outputStream.toString());
        }

        @Test
        void ejectQuarter() {
            gumballMachine.ejectQuarter();
            assertEquals("You haven't inserted a quarter\n", outputStream.toString());
        }

        @Test
        void turnCrank() {
            gumballMachine.turnCrank();

            String expectedString = "You turned, but there's no quarter\n" +
                    "You need to pay first\n";
            assertEquals(expectedString, outputStream.toString());
        }
    }

    @Nested
    class HasQuarterStateTests {
        @BeforeEach
        void setUp() {
            gumballMachine.insertQuarter();
            outputStream.reset();
        }

        @Test
        void insertQuarter() {
            gumballMachine.insertQuarter();
            assertEquals("You can't insert another quarter\n", outputStream.toString());
        }

        @Test
        void ejectQuarter() {
            gumballMachine.ejectQuarter();
            assertEquals("Quarter returned\n", outputStream.toString());
        }

        @Test
        void turnCrank() {
            gumballMachine.turnCrank();

            String expectedString = "You turned...\n" +
                                    "A gumball comes rolling out the slot...\n";
            assertEquals(expectedString, outputStream.toString());
        }
    }

    @Nested
    class SoldOutStateTests {
        @BeforeEach
        void setUp() {
            gumballMachine = new GumballMachine(1);
            gumballMachine.insertQuarter();
            gumballMachine.turnCrank();
            outputStream.reset();
        }

        @Test
        void insertQuarter() {
            gumballMachine.insertQuarter();
            assertEquals("You can't insert a quarter, the machine is sold out\n", outputStream.toString());
        }

        @Test
        void ejectQuarter() {
            gumballMachine.ejectQuarter();
            assertEquals("You can't eject, you haven't inserted a quarter yet\n", outputStream.toString());
        }

        @Test
        void turnCrank() {
            gumballMachine.turnCrank();

            String expectedString = "You turned, but there are no gumballs\n" +
                                    "No gumball dispensed\n";
            assertEquals(expectedString, outputStream.toString());;
        }
    }

    @Nested
    class InitialSoldOutStateTests {
        @BeforeEach
        void setUp() {
            gumballMachine = new GumballMachine(0);
        }

        @Test
        void insertQuarter() {
            gumballMachine.insertQuarter();
            assertEquals("You can't insert a quarter, the machine is sold out\n", outputStream.toString());
        }

        @Test
        void ejectQuarter() {
            gumballMachine.ejectQuarter();
            assertEquals("You can't eject, you haven't inserted a quarter yet\n", outputStream.toString());
        }

        @Test
        void turnCrank() {
            gumballMachine.turnCrank();

            String expectedString = "You turned, but there are no gumballs\n" +
                    "No gumball dispensed\n";
            assertEquals(expectedString, outputStream.toString());;
        }
    }
}