package com.fsferrara.java.filetostring;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloResource {

    @Autowired
    private FileResponse fileResponse;

    @RequestMapping(method = RequestMethod.GET, value = "hello", produces = "application/json;charset=UTF-8")
    public ResponseEntity<String> hello() {
        return ResponseEntity.ok().body(fileResponse.read());
    }

}
