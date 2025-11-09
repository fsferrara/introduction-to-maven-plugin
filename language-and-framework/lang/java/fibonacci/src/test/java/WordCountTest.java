import org.junit.jupiter.api.*;
import org.junit.jupiter.api.BeforeEach;
import static org.junit.jupiter.api.Assertions.*;
//import org.junit.platform.runner.JUnitPlatform;

import java.io.*;

//import org.junit.runner.RunWith;

//@RunWith(JUnitPlatform.class)
public class WordCountTest {
  @Test
  void noFile() {
    Exception ex = assertThrows(RuntimeException.class, () -> WordCount.count("nofile", ""));
    
    assertTrue(ex.getCause() instanceof FileNotFoundException);
  } 
  
  @Test
  void wordCount() {
    assertAll(
      () -> assertEquals(0, WordCount.count("file1.txt", "lambda"))
      , () -> assertEquals(1, WordCount.count("file2.txt", "lambda"))
      , () -> assertEquals(3, WordCount.count("file3.txt", "lambda"))
      , () -> assertEquals(0, WordCount.count("WordCount.java", "lambda"))
      , () -> assertEquals(5, WordCount.count("WordCountTest.java", "lambda"))
    );
  }
}

