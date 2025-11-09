package com.fsferrara.lambdas.expressions.functional_interface;

/**
 * The term Java functional interface was introduced in Java 8.
 * A functional interface in Java is an interface that contains only a single abstract (unimplemented) method.
 * A functional interface can contain default and static methods which do have an implementation, in addition
 * to the single unimplemented method.
 */
public interface MyFunInt {
    String getValue(String input);
}
