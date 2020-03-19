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
public class BMI {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int weight = 85;
        double high = 1.64;
        double BMI = weight / high / high;
        System.out.println("BMI=" + BMI);
        if (BMI > 24) {
            System.out.println("overweight");
        } else if (BMI > 18) {
            System.out.println("fine");
        } else {
            System.out.println("go and eat something");
        }

    }

}
