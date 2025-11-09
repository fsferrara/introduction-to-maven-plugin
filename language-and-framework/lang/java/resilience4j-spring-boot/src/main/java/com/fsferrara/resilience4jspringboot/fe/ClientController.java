package com.fsferrara.resilience4jspringboot.fe;

import com.fsferrara.resilience4jspringboot.pl.externalservice.ExternalServiceClient;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class ClientController {

    @Autowired
    ExternalServiceClient externalServiceClient;

    @GetMapping("/test")
    public String test() {
        return externalServiceClient.exec();
    }

}
