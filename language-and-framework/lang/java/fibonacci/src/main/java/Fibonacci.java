import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

class NextInSeries {
  public final int current;
  public final int next;

  public NextInSeries(int theCurr, int theNext) {
    current = theCurr;
    next = theNext;
  }

  public NextInSeries next() {
    return new NextInSeries(next, current + next);
  }
}

class Fibonacci {
  public static int numberAtPosition(int position) {
    return Stream.iterate(new NextInSeries(0,1), NextInSeries::next)
        .skip(position)
        .findFirst()
        .get().next;
  }
  
  public static List<Integer> seriesUntilPosition(int position) {
    return IntStream.rangeClosed(0,position)
        .map(Fibonacci::numberAtPosition)
        .boxed()
        .collect(Collectors.toList());
  }

}