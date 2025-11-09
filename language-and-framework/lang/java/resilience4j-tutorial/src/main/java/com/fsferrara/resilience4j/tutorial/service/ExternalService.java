package com.fsferrara.resilience4j.tutorial.service;

import com.fsferrara.resilience4j.tutorial.service.concrete.ExternalServiceClient;
import com.fsferrara.resilience4j.tutorial.service.dto.ExternalServiceRequest;
import com.fsferrara.resilience4j.tutorial.service.dto.ExternalServiceResponse;
import io.github.resilience4j.bulkhead.ThreadPoolBulkhead;
import io.github.resilience4j.circuitbreaker.CircuitBreaker;
import io.github.resilience4j.decorators.Decorators;
import io.github.resilience4j.retry.Retry;

public class ExternalService {

    private static ExternalService instance;
    private static final Object lock = new Object();

    private final ExternalServiceClient client;
    final ThreadPoolBulkhead threadPoolBulkhead;
    final CircuitBreaker circuitBreaker;
    final Retry retry;

    private ExternalService() {
        this.client = new ExternalServiceClient();
        this.threadPoolBulkhead = ThreadPoolBulkhead.ofDefaults("ExternalServiceThreadPool");
        this.circuitBreaker = CircuitBreaker.ofDefaults("ExternalServiceCircuitBreaker");
        this.retry = Retry.ofDefaults("ExternalServiceRetry");
    }

    public ThreadPoolBulkhead getThreadPoolBulkhead() {
        return this.threadPoolBulkhead;
    }

    public static ExternalService getInstance() {
        ExternalService es = instance;
        if (es == null) {
            synchronized (lock) {
                es = instance;
                if (es == null) {
                    es = new ExternalService();
                    instance = es;
                }
            }
        }
        return es;
    }

    public ExternalServiceResponse call(ExternalServiceRequest request) {

        return Decorators.ofSupplier(() -> this.client.call(request))
            .withThreadPoolBulkhead(this.threadPoolBulkhead)
            .withCircuitBreaker(this.circuitBreaker)
            .withRetry(this.retry)
            .decorate()
            .get()
            .toCompletableFuture()
            .join();
    }

}
