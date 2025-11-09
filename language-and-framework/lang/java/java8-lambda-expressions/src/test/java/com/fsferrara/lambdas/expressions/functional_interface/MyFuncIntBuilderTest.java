package com.fsferrara.lambdas.expressions.functional_interface;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MyFuncIntBuilderTest {

    @org.junit.jupiter.api.BeforeEach
    void setUp() {
    }

    @org.junit.jupiter.api.AfterEach
    void tearDown() {
    }

    @Test
    void build() {
        MyFunInt build = MyFuncIntBuilder.build();
        String actual = build.getValue("w");
        assertEquals("ww", actual);
    }
}