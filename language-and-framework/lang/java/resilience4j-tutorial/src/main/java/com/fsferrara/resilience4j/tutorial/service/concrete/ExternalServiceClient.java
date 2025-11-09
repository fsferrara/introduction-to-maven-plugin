package com.fsferrara.resilience4j.tutorial.service.concrete;

import com.fsferrara.resilience4j.tutorial.service.dto.ExternalServiceRequest;
import com.fsferrara.resilience4j.tutorial.service.dto.ExternalServiceResponse;

public class ExternalServiceClient {

    public ExternalServiceClient() {
    }

    public ExternalServiceResponse call(ExternalServiceRequest request) {

        String greeting = createGreeting(request.getName());

        ExternalServiceResponse response = new ExternalServiceResponse();
        response.setGreeting(greeting);

        return response;
    }

    private String createGreeting(String name) {
        StringBuilder greeting = new StringBuilder("Hello");
        if (!"".equals(name)) {
            greeting.append(" ").append(name);
        }
        return greeting.toString();
    }
}
