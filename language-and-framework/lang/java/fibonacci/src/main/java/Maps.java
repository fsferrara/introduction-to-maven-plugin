import static java.util.stream.Collectors.groupingBy;
import static java.util.stream.Collectors.mapping;
import static java.util.stream.Collectors.toSet;

import java.util.*;
import java.util.stream.Collectors;

public class Maps {
  public static Map<Integer, List<String>> listByScore(Map<String, Integer> scores) {
    return scores.entrySet()
        .stream()
        .collect(Collectors.toMap(
            Map.Entry::getValue,
            e -> Collections.singletonList(e.getKey()),
            Maps::merge
        ));
  }

  private static List<String> merge(List<String> a, List<String> b) {
    List<String> ret = new ArrayList<>();
    ret.addAll(a);
    ret.addAll(b);
    return ret;
  }

  private static class MapElem {
    public final Integer score;
    public final Set<String> persons;

    public MapElem(Integer score, Set<String> persons) {
      this.score = score;
      this.persons = persons;
    }
  }

  public static Map<Integer, Set<String>> setByScore(Map<String, Integer> scores) {

    return Maps.listByScore(scores)
        .entrySet()
        .stream()
        .map( e -> new MapElem(e.getKey(), e.getValue()
            .stream()
            .map(String::toUpperCase)
            .collect(toSet())))
        .collect(Collectors.toMap( e -> e.score, e -> e.persons));
  }

  public static Map<Integer, Integer> countScores(Map<String, Integer> scores) {
    Map<Integer, Integer> byScores = new HashMap<>();
    for(String name : scores.keySet()) {
      int score = scores.get(name);

      int count = 0;
      if(byScores.containsKey(score))
        count = byScores.get(score);

      byScores.put(score, count + 1);
    }                            

    return byScores;
  }

  public static Map<Integer, Set<Integer>> numberOfLetters(Map<String, Integer> scores) {
    return scores.keySet()
        .stream()
        .collect(groupingBy(scores::get, mapping(String::length, toSet())));
  }

  private static class ScoreAndLength {
    public Integer score;
    public Integer length;

    public ScoreAndLength(Integer score, Integer length) {
      this.score = score;
      this.length = length;
    }
  }

  public static Map<Integer, Integer> maxNumberOfLetters(Map<String, Integer> scores) {

    return scores.entrySet()
        .stream() // String, Integer
        .map(e -> new ScoreAndLength(e.getValue(), e.getKey().length()))
        .collect(Collectors.toMap(
            e -> e.score,
            e -> e.length,
            Math::max
        ));
  }
}