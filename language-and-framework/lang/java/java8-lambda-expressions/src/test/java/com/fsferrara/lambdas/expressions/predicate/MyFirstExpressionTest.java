package com.fsferrara.lambdas.expressions.predicate;

import com.fsferrara.lambdas.expressions.predicate.MyFirstExpression;

import static org.junit.Assert.assertTrue;

public class MyFirstExpressionTest {

    @org.junit.Test
    public void testExpression() throws Exception {
        MyFirstExpression my = new MyFirstExpression();
        my.expression();
        assertTrue(Boolean.TRUE);
    }
}