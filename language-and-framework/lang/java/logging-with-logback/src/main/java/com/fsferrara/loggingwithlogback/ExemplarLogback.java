package com.fsferrara.loggingwithlogback;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class ExemplarLogback {

    private Logger logger = LoggerFactory.getLogger(ExemplarLogback.class);

    public void test() {

        logger.info("Info message");

    }
}
