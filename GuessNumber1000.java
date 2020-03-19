
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
public class GuessNumber1000 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        float number = (float) Math.random();
        number *= 1000.0f;
        int answer = (int) number;
        Scanner watch = new Scanner(System.in);
        
        while (true) {
            int guess = watch.nextInt();
            if (guess > answer) {
                System.out.println("Tooooooooo large");
            } else if (guess < answer) {
                System.out.println("Tooooooooo small");
            } else {
                System.out.println("Bingo");
            }
        }

    }

}
