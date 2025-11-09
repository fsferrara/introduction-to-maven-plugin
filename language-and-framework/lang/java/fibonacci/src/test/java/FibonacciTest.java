import org.junit.jupiter.api.*;
import org.junit.jupiter.api.BeforeEach;
import static org.junit.jupiter.api.Assertions.*;
//import org.junit.platform.runner.JUnitPlatform;

import java.util.*;

//import org.junit.runner.RunWith;

//@RunWith(JUnitPlatform.class)
public class FibonacciTest {
  @Test
  void numberAtPosition() {
    assertAll(
        () -> assertEquals(1, Fibonacci.numberAtPosition(0))
        , () -> assertEquals(1, Fibonacci.numberAtPosition(1))
        , () -> assertEquals(2, Fibonacci.numberAtPosition(2))
        , () -> assertEquals(3, Fibonacci.numberAtPosition(3))
        , () -> assertEquals(5, Fibonacci.numberAtPosition(4))
        , () -> assertEquals(8, Fibonacci.numberAtPosition(5))
        , () -> assertEquals(89, Fibonacci.numberAtPosition(10))
    );
  }

  @Test
  void series() {
    assertAll(
        () -> assertEquals(Arrays.asList(1), Fibonacci.seriesUntilPosition(0))
        , () -> assertEquals(Arrays.asList(1, 1), Fibonacci.seriesUntilPosition(1))
        , () -> assertEquals(Arrays.asList(1, 1, 2), Fibonacci.seriesUntilPosition(2))
        , () -> assertEquals(Arrays.asList(1, 1, 2, 3), Fibonacci.seriesUntilPosition(3))
        , () -> assertEquals(Arrays.asList(1, 1, 2, 3, 5), Fibonacci.seriesUntilPosition(4))
        , () -> assertEquals(Arrays.asList(1, 1, 2, 3, 5, 8), Fibonacci.seriesUntilPosition(5))
        , () -> assertEquals(Arrays.asList(1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89), Fibonacci.seriesUntilPosition(10))
    );
  }
}

