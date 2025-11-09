package com.fsferrara.resilience4jspringboot;

import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.PropertySource;

@Configuration
@PropertySource("classpath:/actuator.properties")
public class AppConfiguration {

//    @Bean
//    public SecurityWebFilterChain securityWebFilterChain(
//            ServerHttpSecurity http) {
//        return http.authorizeExchange()
//                .pathMatchers("/actuator/**").permitAll()
//                .anyExchange().authenticated()
//                .and().build();
//    }

}
