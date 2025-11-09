package com.fsferrara.lambdas.expressions.functional_interface;

/**
 * A Java functional interface can be implemented by a Java Lambda Expression.
 */
public class MyFuncIntBuilder {

    /**
     * Here is an example that implements the functional interface {@link MyFunInt}.
     * @return the functional interface implementation.
     */
    public static MyFunInt build() {
        return value -> value+value;
    }

}
