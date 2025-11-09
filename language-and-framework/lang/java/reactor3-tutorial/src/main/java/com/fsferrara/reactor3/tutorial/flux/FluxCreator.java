package com.fsferrara.reactor3.tutorial.flux;

import reactor.core.publisher.Flux;

public class FluxCreator {

    /**
     * Return an empty Flux.
     */
    Flux<Void> emptyFlux() {
        return Flux.empty();
    }

    /**
     *     Return a Flux that contains 2 values "foo" and "bar" without using an array or a collection
     */
    Flux<String> fooBarFluxFromValues() {
        return Flux.just("foo", "bar");
    }

}
