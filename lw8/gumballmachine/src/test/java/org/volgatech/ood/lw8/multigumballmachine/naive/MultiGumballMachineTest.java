package org.volgatech.ood.lw8.multigumballmachine.naive;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Nested;
import org.junit.jupiter.api.Test;
import org.volgatech.ood.lw8.gumballmachine.GumballMachine;

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
            gumballMachine.ejectQuarter();
            assertEquals("You haven't inserted a quarter\n", outputStream.toString());
        }

        @Test
        void turnCrank() {
            gumballMachine.turnCrank();
            assertEquals("You turned, but there's no quarter\n", outputStream.toString());
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
        void tryingToInsertQuarter() {
            for (int i = 0; i < 4; i++) {
                gumballMachine.insertQuarter();
            }
            outputStream.reset();

            gumballMachine.insertQuarter();
            assertEquals("Max number of quarters\n", outputStream.toString());
        }

        @Test
        void ejectQuarters() {
            gumballMachine.insertQuarter();
            outputStream.reset();

            gumballMachine.ejectQuarter();
            String expectedStr = "Quarter returned\n" + "Quarter returned\n";
            assertEquals(expectedStr, outputStream.toString());
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
            gumballMachine.ejectQuarter();
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

            gumballMachine.ejectQuarter();
            assertEquals("Quarter returned\n", outputStream.toString());
        }

        @Test
        void turnCrank() {
            gumballMachine.turnCrank();
            assertEquals("You turned, but there are no gumballs\n", outputStream.toString());;
        }
    }

    @Nested
    class InitialSoldOutStateTests {
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
            gumballMachine.ejectQuarter();
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

            gumballMachine.ejectQuarter();
            assertEquals("Quarter returned\n", outputStream.toString());
        }

        @Test
        void turnCrank() {
            gumballMachine.turnCrank();
            assertEquals("You turned, but there are no gumballs\n", outputStream.toString());;
        }
    }

    @Test
    void refillTest() {
        gumballMachine.refill(2);
        assertEquals("Refill gum balls with 2 count\n", outputStream.toString());
    }
}