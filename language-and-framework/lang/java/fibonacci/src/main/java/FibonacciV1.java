import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class FibonacciV1 {
  public static int numberAtPosition(int position) {
    if(position < 2) return 1;
    return numberAtPosition(position-1) + numberAtPosition(position-2);
  }
  
  public static List<Integer> seriesUntilPosition(int position) {
    return IntStream.rangeClosed(0,position)
        .map(FibonacciV1::numberAtPosition)
        .boxed()
        .collect(Collectors.toList());
  } 
}