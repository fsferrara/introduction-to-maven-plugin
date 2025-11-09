import org.junit.jupiter.api.*;
import org.junit.jupiter.api.BeforeEach;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.platform.runner.JUnitPlatform;

import java.util.*;                     

public class SolutionTest {

	private static Solution underTest;
	
	@BeforeAll
	static void before() {
		underTest = new Solution();
	}
	
	@Test
	void solution() {
		assertAll(
			() -> assertEquals(23, underTest.run(10)),
			() -> assertEquals(233168, underTest.run(1000))
		);
	}
}
