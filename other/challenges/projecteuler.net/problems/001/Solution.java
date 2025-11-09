import java.util.stream.IntStream;

public class Solution {
	public int run(int n) {
		return IntStream.range(0, n)
			.filter(i -> i % 3 == 0 || i % 5 == 0)
			.sum();
	}
}
