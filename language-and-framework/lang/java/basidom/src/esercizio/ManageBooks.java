package esercizio;

import java.io.File;
import javax.xml.parsers.*;
import javax.xml.transform.*;
import javax.xml.transform.dom.*;
import javax.xml.transform.stream.*;
import org.w3c.dom.*;

public class ManageBooks {

	public static void main(String[] args) {
		
		File outfile = new File("xml/extract.xml");

		try {

			DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
			DocumentBuilder builder = factory.newDocumentBuilder();
			Document doc = builder.parse("xml/books.xml");
			NodeList list = doc.getElementsByTagName("book");

			for (int i = 0; i < list.getLength(); i++) { //Tutti i libri

				Element element = (Element) list.item(i); // Prendo un elemento <book>
				
				NodeList figli = element.getChildNodes(); // Figli dell'elemento <book>
				for (int k = 0; k < figli.getLength(); k++) {
					Node figlio = figli.item(k);
					
					if (!figlio.getNodeName().equals("description") & figlio.getNodeType() == 1) {
						
						// Inserimento attributo
						element.setAttribute(figlio.getNodeName(), figlio.getFirstChild().getNodeValue());

						// Eliminazione tag figlio
						Node removeChild = element.removeChild(figlio);

					}

				}

				if (!element.getAttribute("genre").equals("Computer")) {

					// Rimozione elemento corrente
					element.getParentNode().removeChild(element);
					i--;

				}

			}

			Transformer tFormer = TransformerFactory.newInstance().newTransformer();
			tFormer.setOutputProperty(OutputKeys.METHOD, "xml");
			doc.normalize();
			Source source = new DOMSource(doc);
			Result result = new StreamResult(outfile);
			tFormer.transform(source, result);

		}
		catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}

}
