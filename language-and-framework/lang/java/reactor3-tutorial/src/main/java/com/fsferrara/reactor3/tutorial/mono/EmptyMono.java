package com.fsferrara.reactor3.tutorial.mono;

import reactor.core.publisher.Mono;

public class EmptyMono {

    public Mono<Void> emptyMono() {
        return Mono.empty();
    }

}
