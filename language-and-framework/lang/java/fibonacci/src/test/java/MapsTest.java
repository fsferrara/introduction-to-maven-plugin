import org.junit.jupiter.api.*;
import org.junit.jupiter.api.BeforeEach;
import static org.junit.jupiter.api.Assertions.*;
//import org.junit.platform.runner.JUnitPlatform;

import java.util.*;

//import org.junit.runner.RunWith;

//@RunWith(JUnitPlatform.class)
public class MapsTest {
  private Map<String, Integer> scores = new HashMap<String, Integer>() {
    {
      put("Jack", 12);
      put("Jill", 15);
      put("Tom", 11);
      put("Darla", 15);
      put("TOM", 11);
      put("Nick", 15);
      put("Nancy", 11);      
    }
  };
  
  @Test
  void scoresList() {                                                               
    assertAll(
      () -> assertEquals(Arrays.asList("Jack"), Maps.listByScore(scores).get(12))
      , () -> assertEquals(3, Maps.listByScore(scores).get(15).size())
      , () -> assertTrue(Maps.listByScore(scores).get(15).contains("Darla"))
      , () -> assertEquals(3, Maps.listByScore(scores).get(11).size())
      , () -> assertTrue(Maps.listByScore(scores).get(11).contains("Tom"))
      , () -> assertTrue(Maps.listByScore(scores).get(11).contains("TOM"))
    );
  }

  @Test
  void scoresSet() {                                                               
    assertAll(
      () -> assertTrue(Maps.setByScore(scores).get(12).contains("JACK"))
      , () -> assertEquals(3, Maps.setByScore(scores).get(15).size())
      , () -> assertTrue(Maps.setByScore(scores).get(15).contains("DARLA"))
      , () -> assertEquals(2, Maps.setByScore(scores).get(11).size())
      , () -> assertTrue(Maps.setByScore(scores).get(11).contains("TOM"))
    );
  }

  @Test
  void scoresCount() {                                                               
    assertAll(
      () -> assertEquals(1, (int) Maps.countScores(scores).get(12))
      , () -> assertEquals(3, (int) Maps.countScores(scores).get(11))
      , () -> assertEquals(3, (int) Maps.countScores(scores).get(15))
    );
  }

  @Test
  void numberOfLetters() {                                                               
    assertAll(
      () -> assertTrue(Maps.numberOfLetters(scores).get(12).contains(4))
      , () -> assertTrue(Maps.numberOfLetters(scores).get(15).contains(5))
      , () -> assertTrue(Maps.numberOfLetters(scores).get(15).contains(4))
      , () -> assertTrue(Maps.numberOfLetters(scores).get(11).contains(5))
      , () -> assertTrue(Maps.numberOfLetters(scores).get(11).contains(3))
    );
  }

  @Test
  void maxNumberOfLetters() {                                                               
    assertAll(
      () -> assertEquals(4, (int) Maps.maxNumberOfLetters(scores).get(12))
      , () -> assertEquals(5, (int) Maps.maxNumberOfLetters(scores).get(15))
      , () -> assertEquals(5, (int) Maps.maxNumberOfLetters(scores).get(11))
    );
  }
}

