import javax.media.*;
import java.io.File;
import java.io.IOException;

public class BasicAudioPlayer
{
  private Player audioPlayer = null;


  public BasicAudioPlayer (File file) throws IOException,
      NoPlayerException, CannotRealizeException
  {
    // Converte il file in un oggetto di tipo URL e richiama
    // il metodo statico createRealizedPlayer
    audioPlayer = Manager.createRealizedPlayer(file.toURL());
  }
  
  public void playAudioFile()
  {
    audioPlayer.start();
  }

  public void stopAudioFile()
  {
    audioPlayer.stop();
    audioPlayer.close();
  }

  public static void main(String[] args)
  {
    try
    {
      if (args.length == 1)
      {
        File audioFile = new File(args[0]);
        BasicAudioPlayer player = new BasicAudioPlayer(audioFile);

        System.out.println("Inizio riproduzione del file '" +
            audioFile.getAbsolutePath() + "'");
        System.out.println("Premere INVIO per interrompere la " +
            "riproduzione ed uscire dal programma");

        player.playAudioFile();

        // Rimane in attesa della pressione del tasto INVIO
        System.in.read();
        System.out.println("Interruzione ed uscita dal programma");
        player.stopAudioFile();
      }
      else
      {
        // Non è stato fornito il nome del file in input
        System.out.println("È necessario fornire in input il nome "
            + "del file da riprodurre");
      }
    }
    catch (Exception ex)
    {
      ex.printStackTrace();
    }

    System.exit(0);
  }
} 