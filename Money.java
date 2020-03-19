/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.firsttry;

/**
 *
 * @author Calvin Wan
 */
public class Money {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int have = 10, saferange = 8, buy = 5;
        int now = have - buy;
        int need = saferange - now;
        if (now < saferange) {
            System.out.println("need help" + need);
        } else {
            System.out.println("need nothing");
        }
        int cost = buy * 25;
        int act = 200;
        int z = act - cost;
        //a=number of 50
        long a = z / 50;
        long b = z % 50;
        long c = b / 10;
        long d = b % 10;
        long e = d / 5;
        long f = d % 5;
        System.out.println("  50=>" + a + "  10=>" + c + "  5=>" + e + "  1=>" + f);
    }
}
