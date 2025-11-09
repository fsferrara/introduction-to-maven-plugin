package com.fsferrara.spring_aop_example;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * Simple Main.
 * @author fsferrara
 */
public class Main {

    private final HelloWorld helloWorld;

    /**
     * Simple auto-wired constructor.
     *
     * @param helloWorld the application bean proxied by spring AOP.
     */
    @Autowired
    public Main(HelloWorld helloWorld) {
        this.helloWorld = helloWorld;
    }

    /**
     * Calls the proxied method.
     */
    public void start() {
        this.helloWorld.printHello();
    }

    /**
     * Starts Spring application context.
     *
     * @param args if any
     */
    public static void main(String[] args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring/applicationContext.xml");
        Main main = (Main) context.getBean("main");
        main.start();
    }
}
