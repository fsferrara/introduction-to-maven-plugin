package com.fsferrara.resilience4j.tutorial;

import com.fsferrara.resilience4j.tutorial.service.ExternalService;
import com.fsferrara.resilience4j.tutorial.service.dto.ExternalServiceRequest;
import com.fsferrara.resilience4j.tutorial.service.dto.ExternalServiceResponse;

class ExternalServiceConsumer {

    private final long millis;
    private final ExternalService externalService;

    public ExternalServiceConsumer(long millis) {
        this.millis = millis;
        this.externalService = ExternalService.getInstance();
    }

    public void run() {
        Thread t = new Thread(() -> {
            while (true) {
                hitTheExternalService();
                try {
                    Thread.sleep(millis);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });
        t.setDaemon(true);
        t.start();
    }

    private void hitTheExternalService() {
        ExternalServiceRequest request = new ExternalServiceRequest();
        request.setName("Mr. Foo");
        ExternalServiceResponse response = this.externalService.call(request);
        System.out.println(response.getGreeting());
    }
}
