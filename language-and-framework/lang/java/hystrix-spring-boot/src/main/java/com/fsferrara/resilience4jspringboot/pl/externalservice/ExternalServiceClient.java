package com.fsferrara.resilience4jspringboot.pl.externalservice;

import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;

@FeignClient(name = "external-service-client", url = "http://localhost:8080", configuration = FeignConfiguration.class)
public interface ExternalServiceClient {

    @GetMapping("/foo")
    String foo();

    @GetMapping("/foooo")
    String foooo();
}
