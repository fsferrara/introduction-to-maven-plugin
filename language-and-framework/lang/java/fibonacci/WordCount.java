import java.io.*;

public class WordCount {
  public static long count(String path, String searchWord) {
    try {
      BufferedReader bufferedReader =
        new BufferedReader(new FileReader(path));
      
      String line = null;

      long count = 0;
      while((line = bufferedReader.readLine()) != null) {
        if(line.contains(searchWord))
          count++;
      }
      
      return count;
    } catch(Exception ex) {
      throw new RuntimeException(ex);
    }
  }
}