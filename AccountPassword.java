package com.mycompany.firsttry;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Calvin Wan
 */
import java.util.Scanner;

public class AccountPassword {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int account = 1234;
        int password = 5678;
        Scanner sca = new Scanner(System.in);
        System.out.println("account here");
        int ACCOUNT = sca.nextInt();
        System.out.println("password here");
        int PASSWORD = sca.nextInt();
        if (PASSWORD == password & ACCOUNT == account) {
            System.out.println("OK,fine,let you go");
        } else {
            System.out.println("get out from here");
        }

    }

}
