package com.fsferrara.resilience4jspringboot.pl.externalservice;

import io.github.resilience4j.circuitbreaker.annotation.CircuitBreaker;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;

@FeignClient(name = "external-service-client", url = "http://localhost:8080/foo", configuration = FeignConfiguration.class)
public interface ExternalServiceClient {

    @GetMapping("/bar")
    String exec();

}
