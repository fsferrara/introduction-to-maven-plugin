package com.fsferrara.spring_aop_example;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Component;


/**
 * Simple Hello World Bean.
 * @author fsferrara
 */
@Component
public class HelloWorld {
    private final Logger logger = LoggerFactory.getLogger(HelloWorld.class);

    /**
     * Prints a sentence.
     */
    @PointcutExample
    public void printHello() {
        logger.info("I don't know anything about the aspect!");
    }

}
