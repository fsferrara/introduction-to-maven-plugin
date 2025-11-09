package com.fsferrara.resilience4j.tutorial;

public class MainClass {

    public static void main(String[] args) {
        System.out.println("Starting...");
        new ExternalServiceConsumer(2000L).run();
        new ExternalServiceMonitoring(2000L).run();
        sleepForever();
    }

    private static void sleepForever() {
        //Handles ctrl+C
        Runtime.getRuntime().addShutdownHook(new Thread( () -> System.out.println("\nHalt!")));
        try {
            Thread.sleep(Long.MAX_VALUE); // Sleep "forever"
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
