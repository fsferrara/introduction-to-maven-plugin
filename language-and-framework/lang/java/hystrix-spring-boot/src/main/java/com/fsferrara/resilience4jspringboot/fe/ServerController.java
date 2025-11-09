package com.fsferrara.resilience4jspringboot.fe;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class ServerController {

    @GetMapping("/foo")
    public String fooBar() {
        try {
            Thread.sleep(100l);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return "ok";
    }


    @GetMapping("/foooo")
    public String fooooBar() {
        try {
            Thread.sleep(10000l);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return "ok";
    }
}
