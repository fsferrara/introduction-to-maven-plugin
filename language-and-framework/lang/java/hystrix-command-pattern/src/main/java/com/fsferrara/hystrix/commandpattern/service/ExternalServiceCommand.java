package com.fsferrara.hystrix.commandpattern.service;

import com.fsferrara.hystrix.commandpattern.service.concrete.ExternalService;
import com.fsferrara.hystrix.commandpattern.service.dto.ExternalServiceRequest;
import com.fsferrara.hystrix.commandpattern.service.dto.ExternalServiceResponse;
import com.netflix.hystrix.HystrixCommand;
import com.netflix.hystrix.HystrixCommandGroupKey;

public class ExternalServiceCommand extends HystrixCommand<ExternalServiceResponse> {

    public static final String HYSTRIX_COMMAND_GROUP_KEY = "ExternalServiceCommand";

    private final ExternalServiceRequest request;

    public ExternalServiceCommand(ExternalServiceRequest request) {
        super(Setter.withGroupKey(HystrixCommandGroupKey.Factory.asKey(HYSTRIX_COMMAND_GROUP_KEY)));
        this.request = request;
    }

    @Override
    protected ExternalServiceResponse run() throws Exception {
        ExternalService service = ExternalService.getInstance();
        return service.action(request);
    }
}
