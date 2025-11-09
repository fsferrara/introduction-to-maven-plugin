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
			() -> assertEquals(187, underTest.run(90)),
			() -> assertEquals(0, underTest.run(4000000))
		);
	}
}
