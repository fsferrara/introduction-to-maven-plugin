package com.fsferrara.lambdas.expressions.predicate;

import java.util.function.Predicate;

public class MyFirstExpression {
    public void expression() {
        // Return true if x > 5
        Predicate<Integer> gt5 = x -> x > 5;

        System.out.println("Testing lambdas: " + gt5.test(5));
    }
}
