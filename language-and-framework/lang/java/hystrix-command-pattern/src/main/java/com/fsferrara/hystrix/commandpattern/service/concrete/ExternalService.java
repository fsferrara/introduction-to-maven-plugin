package com.fsferrara.hystrix.commandpattern.service.concrete;

import com.fsferrara.hystrix.commandpattern.service.dto.ExternalServiceRequest;
import com.fsferrara.hystrix.commandpattern.service.dto.ExternalServiceResponse;

public class ExternalService {

    private static ExternalService instance;
    private static final Object lock = new Object();

    private ExternalService() {
    }

    public static ExternalService getInstance() {
        ExternalService r = instance;
        if (r == null) {
            synchronized (lock) {
                r = instance;
                if (r == null) {
                    r = new ExternalService();
                    instance = r;
                }
            }
        }
        return r;
    }

    public ExternalServiceResponse action(ExternalServiceRequest request) {

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
