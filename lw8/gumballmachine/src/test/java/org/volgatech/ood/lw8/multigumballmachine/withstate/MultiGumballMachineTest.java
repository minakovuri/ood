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
            gumballMachine = new MultiGumballMachine(3);
            gumballMachine.insertQuarter();
            assertEquals("Inserting #1 quarter\n", outputStream.toString());
        }

        @Test
        void ejectQuarter() {
            gumballMachine = new MultiGumballMachine(3);
            gumballMachine.ejectQuarters();
            assertEquals("You haven't inserted a quarter\n", outputStream.toString());
        }

        @Test
        void turnCrank() {
            gumballMachine = new MultiGumballMachine(3);
            gumballMachine.turnCrank();

            String expectedStr = "You turned, but there's no quarter\n" +
                    "You need to pay first\n";
            assertEquals(expectedStr, outputStream.toString());
        }

        @Test
        void refill() {
            gumballMachine = new MultiGumballMachine(3);
            int quartersCount = gumballMachine.quartersCount;
            gumballMachine.refill(4);
            assertEquals("Refill gumballs: 4\n", outputStream.toString());
            assertEquals(quartersCount, gumballMachine.quartersCount);
        }
    }

    @Nested
    class HasQuarterStateTests {
        @Test
        void insertQuarter() {
            gumballMachine = new MultiGumballMachine(3);
            gumballMachine.insertQuarter();
            outputStream.reset();

            gumballMachine.insertQuarter();
            assertEquals("Inserting #2 quarter\n", outputStream.toString());
        }

        @Test
        void ejectQuarters() {
            gumballMachine = new MultiGumballMachine(3);
            gumballMachine.insertQuarter();
            outputStream.reset();

            gumballMachine.ejectQuarters();
            assertEquals("Quarter returned\n", outputStream.toString());
        }

        @Test
        void turnCrank() {
            gumballMachine = new MultiGumballMachine(3);
            gumballMachine.insertQuarter();
            outputStream.reset();

            gumballMachine.turnCrank();
            String expectedString = "You turned...\n" +
                    "A gumball comes rolling out the slot...\n";
            assertEquals(expectedString, outputStream.toString());
        }

        @Test
        void refill() {
            gumballMachine = new MultiGumballMachine(3);
            gumballMachine.insertQuarter();
            outputStream.reset();

            int quartersCount = gumballMachine.quartersCount;
            gumballMachine.refill(4);
            assertEquals("Refill gumballs: 4\n", outputStream.toString());
            assertEquals(quartersCount, gumballMachine.quartersCount);
        }
    }

    @Nested
    class SoldOutStateTests {
        @Test
        void insertQuarter() {
            gumballMachine = new MultiGumballMachine(1);
            gumballMachine.insertQuarter();
            gumballMachine.turnCrank();
            outputStream.reset();

            gumballMachine.insertQuarter();
            assertEquals("You can't insert a quarter, the machine is sold out\n", outputStream.toString());
        }

        @Test
        void ejectQuarter() {
            gumballMachine = new MultiGumballMachine(1);
            gumballMachine.insertQuarter();
            gumballMachine.turnCrank();
            outputStream.reset();

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
            gumballMachine = new MultiGumballMachine(1);
            gumballMachine.insertQuarter();
            gumballMachine.turnCrank();
            outputStream.reset();

            gumballMachine.turnCrank();
            String expectedStr = "You turned, but there are no gumballs\n" +
                                "No gumball dispensed\n";
            assertEquals(expectedStr, outputStream.toString());;
        }

        @Test
        void refill() {
            gumballMachine = new MultiGumballMachine(1);
            gumballMachine.insertQuarter();
            gumballMachine.turnCrank();
            outputStream.reset();

            int quartersCount = gumballMachine.quartersCount;
            gumballMachine.refill(4);
            assertEquals("Refill gumballs: 4\n", outputStream.toString());
            assertEquals(quartersCount, gumballMachine.quartersCount);
        }
    }

    @Nested
    class MaxQuartersStateTests {
        @Test
        void insertQuarter() {
            gumballMachine = new MultiGumballMachine(5);
            for (int i = 0; i < 5; i++) {
                gumballMachine.insertQuarter();
            }
            outputStream.reset();

            gumballMachine.insertQuarter();
            assertEquals("Max number of quarters\n", outputStream.toString());
        }

        @Test
        void ejectQuarters() {
            gumballMachine = new MultiGumballMachine(5);
            for (int i = 0; i < 5; i++) {
                gumballMachine.insertQuarter();
            }
            outputStream.reset();

            gumballMachine.ejectQuarters();
            StringBuilder expectedStr = new StringBuilder();
            for (int i = 0; i < 5; i++) {
                expectedStr.append("Quarter returned\n");
            }
            assertEquals(expectedStr.toString(), outputStream.toString());
        }

        @Test
        void turnCrank() {
            gumballMachine = new MultiGumballMachine(5);
            for (int i = 0; i < 5; i++) {
                gumballMachine.insertQuarter();
            }
            outputStream.reset();

            gumballMachine.turnCrank();

            String expectedString = "You turned...\n" +
                    "A gumball comes rolling out the slot...\n";
            assertEquals(expectedString, outputStream.toString());
        }

        @Test
        void refill() {
            gumballMachine = new MultiGumballMachine(5);
            for (int i = 0; i < 5; i++) {
                gumballMachine.insertQuarter();
            }
            outputStream.reset();

            int quartersCount = gumballMachine.quartersCount;
            gumballMachine.refill(4);
            assertEquals("Refill gumballs: 4\n", outputStream.toString());
            assertEquals(quartersCount, gumballMachine.quartersCount);
        }
    }
}