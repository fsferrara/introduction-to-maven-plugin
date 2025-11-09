Feature: HttpPing

    Scenario: Login functionality exists

        Given I have the url: "https://www.google.com/"
        When I request an HTTP get
        Then I get the status code: "200"
