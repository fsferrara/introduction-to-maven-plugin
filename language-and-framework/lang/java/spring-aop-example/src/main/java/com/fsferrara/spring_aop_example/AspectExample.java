package com.fsferrara.spring_aop_example;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.springframework.stereotype.Component;

/**
 * Example of an Aspect Advice definition.
 *
 * @author fsferrara
 */
@Component
@Aspect
public class AspectExample {

    /**
     * Define WHAT the aspect do and WHEN to do it.
     * - WHAT: the method source code
     * - WHEN: "around" the method
     *
     * @param pjp the join point selected by the pointcut.
     * @return any object that the proxied method might return.
     * @throws Throwable anything that the proxied object might throw.
     */
    @Around(value = "@annotation(PointcutExample)")
    public Object whatThisAspectDo(ProceedingJoinPoint pjp) throws Throwable {
        Object returnObject;
        try {
            returnObject = pjp.proceed();
        } catch (Throwable throwable) {
            throw throwable;
        }
        return returnObject;
    }

}
