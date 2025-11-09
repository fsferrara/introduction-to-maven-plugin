package com.fsferrara.resilience4jspringboot;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.openfeign.EnableFeignClients;

@SpringBootApplication
@EnableFeignClients
public class MainSpringBootApplication {

	public static void main(String[] args) {
		SpringApplication.run(MainSpringBootApplication.class, args);
	}

}
