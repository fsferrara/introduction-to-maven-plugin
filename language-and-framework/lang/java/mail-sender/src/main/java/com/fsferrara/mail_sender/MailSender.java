/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.fsferrara.mail_sender;

/**
 *
 * @author fsferrara
 */
public class MailSender {
    public static void main(String[] args) {
        System.out.println("Start sending mail");
        SendMailTLS sender = new SendMailTLS();
        //SendMailSSL sender = new SendMailSSL();
        sender.send();
        System.out.println("Done");
    }
}
