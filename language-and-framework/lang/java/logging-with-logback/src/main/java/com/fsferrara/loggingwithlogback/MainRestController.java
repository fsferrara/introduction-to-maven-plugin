package com.fsferrara.loggingwithlogback;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class MainRestController {

    @GetMapping("/test")
    String testEndpoint() {

        ExemplarLogback exemplarLogback = new ExemplarLogback();
        exemplarLogback.test();

        return "hello";
    }
}
