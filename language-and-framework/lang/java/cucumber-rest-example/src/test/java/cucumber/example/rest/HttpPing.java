package cucumber.example.rest;

import static org.junit.Assert.assertEquals;

import cucumber.annotation.en.Given;
import cucumber.annotation.en.Then;
import cucumber.annotation.en.When;
import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;

import java.io.IOException;

public class HttpPing {

    private CloseableHttpClient httpClient;
    private HttpGet request;
    private HttpResponse response;
    private String targetUrl;

    /**
     * Setting all the parameters.
     * @param targetUrl
     */
    @Given("^I have the url: \"([^\"]*)\"$")
    public void openBrowser(String targetUrl) {
        this.targetUrl = targetUrl;
    }

    /**
     * Actually perform the REST call
     */
    @When("^I request an HTTP get$")
    public void goToFacebook() {
        httpClient = HttpClients.createDefault();
        request = new HttpGet(targetUrl);
        try {
            response = httpClient.execute(request);
        } catch (IOException e) {
            response = null;
        }
    }

    /**
     * Check the result.
     * @param expectedStatusCode
     */
    @Then("^I get the status code: \"([^\"]*)\"$")
    public void loginButton(Integer expectedStatusCode) {
        System.out.println(">> " + response.getStatusLine().getStatusCode() + " " + response.getStatusLine().getReasonPhrase());
        assertEquals(expectedStatusCode.intValue(), response.getStatusLine().getStatusCode());
    }
}
