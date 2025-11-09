package com.fsferrara.reactor3.tutorial.mono;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import reactor.core.publisher.Mono;
import reactor.test.StepVerifier;

import static org.junit.jupiter.api.Assertions.*;

class EmptyMonoTest {

    private EmptyMono underTest;

    @BeforeEach
    void setUp() {
        underTest = new EmptyMono();
    }

    @AfterEach
    void tearDown() {
    }

    @Test
    void emptyMono() {
        Mono<Void> mono = underTest.emptyMono();
        StepVerifier.create(mono)
                .expectNextCount(0)
                .verifyComplete();
    }
}