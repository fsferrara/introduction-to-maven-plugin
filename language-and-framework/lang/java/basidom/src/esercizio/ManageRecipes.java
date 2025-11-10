/**
 * Classe ManageRecipes (esercizio).
 * traccia:
 * 
 * Scrivere un programma che:
 * 1. Legge il file XML Recipes.xml e contare e contare quante ricette sono presenti
 * 2. Converte tutti i figli di tipo step di ogni ricetta in uno nodo di tipo <procedimento>
 * 3. Mostra solo i nodi <recipes>  che hanno tra l'ingrediente "flour"
 * 4. Salvare il risultato dell'elaborazione in un file extract.xml
 *
 * @author Francesco Saverio Ferrara
 * @author Francesco Pane
 * @author Giovanni Scala
 * @version 0.1
*/

package esercizio;

import java.io.File;
import javax.xml.parsers.*;
import javax.xml.transform.*;
import javax.xml.transform.dom.*;
import javax.xml.transform.stream.*;
import org.w3c.dom.*;

public class ManageRecipes {

	public static void main(String[] args) {

		File outfile = new File("xml/extract.xml");

		try {
			DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
			DocumentBuilder builder = factory.newDocumentBuilder();
			Document doc = builder.parse("xml/recipes.xml");

			NodeList list = doc.getElementsByTagName("rcp:recipe"); //Prendo tutte le ricette
			System.out.println("Ci sono " + list.getLength() + " ricette nel file xml recipes.xml!!!");
			
			for (int i=0 ; i<list.getLength() ; i++) { //Per ogni ricetta
				
				Node ricetta = list.item(i); //prendo la ricetta i-esima
				
				/*
				 * I nodi figli di ricetta possono essere di vario tipo, a noi interessano
				 * solo rcp:preparation e rcp:ingredient per svolgere questo esercizio
				 */
				NodeList figliRicetta = ricetta.getChildNodes();
				
				boolean trovatoFlour = false;
				for (int j=0 ; j<figliRicetta.getLength() ; j++) {
					Node figlioRicetta = figliRicetta.item(j);
					if (figlioRicetta.getNodeName() == "rcp:preparation") {
						
						NodeList steps = figlioRicetta.getChildNodes();
						String tmp = "";
						for (int k=0 ; k<steps.getLength() ; k++) {
							Node step = steps.item(k);
							if (step.getNodeName() == "rcp:step") {
								tmp = tmp + step.getFirstChild().getNodeValue() + " ";
								step.removeChild(step.getFirstChild());
							}

							if (step.getNodeType() == 1) //Se e' un elemento XML
								figlioRicetta.removeChild(step);
						}
						
						figlioRicetta.getFirstChild().setNodeValue(tmp);
					}
					
					if (figlioRicetta.getNodeName() == "rcp:ingredient") {
						NamedNodeMap attributiIngrediente = figlioRicetta.getAttributes();
						if (attributiIngrediente.getNamedItem("name").getNodeValue() == "flour") {
							trovatoFlour = true; //Se trovo l'ingrediente
						}
					}
					
				}
				
				if (!trovatoFlour) { //Se non ho trovato l'ingrediente
					//Cancello la ricetta dal file XML
					doc.getElementsByTagName("rcp:collection").item(0).removeChild(ricetta);
				}
				
			}
			
			Transformer tFormer = TransformerFactory.newInstance().newTransformer();
			tFormer.setOutputProperty(OutputKeys.METHOD, "xml");
			doc.normalize();
			Source source = new DOMSource(doc);
			Result result = new StreamResult(outfile);
			tFormer.transform(source, result);
			
			System.out.println("Il risultato dell'elaborazione e' stato scritto nel file extract.xml");
			
		}
		catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}

}
