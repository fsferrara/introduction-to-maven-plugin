package com.fsferrara.reactor3.tutorial.flux;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import reactor.core.publisher.Flux;
import reactor.test.StepVerifier;

class FluxCreatorTest {

    private FluxCreator underTest;

    @BeforeEach
    void setUp() {
        underTest = new FluxCreator();
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void emptyFlux() {
        Flux<Void> flux = underTest.emptyFlux();
        StepVerifier.create(flux)
                .expectNextCount(0)
                .verifyComplete();
    }

    @Test
    void fooBarFluxFromValues() {
        Flux<String> flux = underTest.fooBarFluxFromValues();
        StepVerifier.create(flux)
                .assertNext(s -> "foo".equals(s))
                .assertNext(s -> "bar".equals(s))
                .verifyComplete();
    }
}