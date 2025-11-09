package com.fsferrara.hystrix.commandpattern;

import com.fsferrara.hystrix.commandpattern.service.ExternalServiceCommand;
import com.fsferrara.hystrix.commandpattern.service.dto.ExternalServiceRequest;
import com.fsferrara.hystrix.commandpattern.service.dto.ExternalServiceResponse;

class ExternalServiceClient {

    private final long millis;

    public ExternalServiceClient(long millis) {
        this.millis = millis;
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
        ExternalServiceCommand command = new ExternalServiceCommand(request);
        ExternalServiceResponse response = command.execute();
        System.out.println(response.getGreeting());
    }
}
