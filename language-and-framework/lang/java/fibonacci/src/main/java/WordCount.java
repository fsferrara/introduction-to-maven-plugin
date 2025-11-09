import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;

public class WordCount {
  public static long count(String path, String searchWord) {


    try {
      return Files
          .lines(Paths.get(path))
          .filter(string -> string.contains(searchWord))
          .count();

    } catch(Exception ex) {
      throw new RuntimeException(new FileNotFoundException());
    }
  }
}