package com.fsferrara.resilience4jspringboot;

import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.PropertySource;

@Configuration
@PropertySource("classpath:/actuator.properties")
public class AppConfiguration {
}
