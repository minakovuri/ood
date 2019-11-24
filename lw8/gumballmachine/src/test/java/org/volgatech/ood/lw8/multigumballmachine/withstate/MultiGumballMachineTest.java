package org.volgatech.ood.lw8.multigumballmachine.withstate;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Nested;
import org.junit.jupiter.api.Test;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

import static org.junit.jupiter.api.Assertions.*;

class MultiGumballMachineTest {
    private ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
    private final PrintStream old = System.out;
    private MultiGumballMachine gumballMachine;

    @BeforeEach
    void setUp() {
        PrintStream printStream = new PrintStream(outputStream);
        System.setOut(printStream);

        gumballMachine = new MultiGumballMachine(5);
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
            assertEquals("Inserting #1 quarter\n", outputStream.toString());
        }

        @Test
        void ejectQuarter() {
            gumballMachine.ejectQuarters();
            assertEquals("You haven't inserted a quarter\n", outputStream.toString());
        }

        @Test
        void turnCrank() {
            gumballMachine.turnCrank();

            String expectedStr = "You turned, but there's no quarter\n" +
                    "You need to pay first\n";
            assertEquals(expectedStr, outputStream.toString());
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
            assertEquals("Inserting #2 quarter\n", outputStream.toString());
        }

        @Test
        void ejectQuarters() {
            gumballMachine.ejectQuarters();
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
            gumballMachine = new MultiGumballMachine(1);
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
            gumballMachine.ejectQuarters();
            assertEquals("You can't eject, you haven't inserted a quarter yet\n", outputStream.toString());
        }

        @Test
        void ejectAllQuarters() {
            gumballMachine = new MultiGumballMachine(2);
            gumballMachine.insertQuarter();
            gumballMachine.insertQuarter();
            gumballMachine.insertQuarter();
            gumballMachine.turnCrank();
            gumballMachine.turnCrank();
            outputStream.reset();

            gumballMachine.ejectQuarters();
            assertEquals("Quarter returned\n", outputStream.toString());
        }

        @Test
        void turnCrank() {
            gumballMachine.turnCrank();

            String expectedStr = "You turned, but there are no gumballs\n" +
                                "No gumball dispensed\n";
            assertEquals(expectedStr, outputStream.toString());;
        }
    }

    @Nested
    class MaxQuartersStateTests {
        @BeforeEach
        void setUp() {
            gumballMachine = new MultiGumballMachine(5);
            for (int i = 0; i < 5; i++) {
                gumballMachine.insertQuarter();
            }
            outputStream.reset();
        }

        @Test
        void insertQuarter() {
            gumballMachine.insertQuarter();
            assertEquals("Max number of quarters\n", outputStream.toString());
        }

        @Test
        void ejectQuarters() {
            gumballMachine.ejectQuarters();

            StringBuilder expectedStr = new StringBuilder();
            for (int i = 0; i < 5; i++) {
                expectedStr.append("Quarter returned\n");
            }

            assertEquals(expectedStr.toString(), outputStream.toString());
        }

        @Test
        void turnCrank() {
            gumballMachine.turnCrank();

            String expectedString = "You turned...\n" +
                    "A gumball comes rolling out the slot...\n";
            assertEquals(expectedString, outputStream.toString());
        }
    }

//    @Test
//    void refill() {
//        gumballMachine.refill(2);
//        assertEquals("Refill gum balls with 2 count\n", outputStream.toString());
//    }
}