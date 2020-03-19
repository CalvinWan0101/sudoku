/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.firsttry;

import java.util.Scanner;

/**
 *
 * @author Calvin Wan
 */
public class Switch {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner watch = new Scanner(System.in);
        int week = watch.nextInt();

        /*if (week == 1) {
            System.out.println("lunch");
        }
        else if (week == 2) {
                    System.out.println("run");
                }
        else {
                    System.out.println("ooo");
                }*/
        switch (week) {
            case 1:
                System.out.println("lunch");
                break;
            case 2:
                System.out.println("run");
                break;
            case 3:
                System.out.println("ooo");
                break;
        }
    }
}
