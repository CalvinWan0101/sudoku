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
public class Homwork {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sca = new Scanner(System.in);
        // i=the number of the customer
        // Alcohol=A;Mask=M
        int priceM = 5;
        int priceA = 25;
        int i = 0;
        while (i > -1) {
            i++;
            System.out.println("請輸入您要購買口罩的數量");
            int buyM = sca.nextInt();
            System.out.println("請輸入您要購買酒精的數量");
            int buyA = sca.nextInt();
            int moneyA = buyA * priceA;
            int moneyM = buyM * priceM;
            int moneyall = moneyM + moneyA;
            System.out.println("您已經購買口罩" + buyM + "個，酒精" + buyA + "瓶酒精，總共是" + moneyall + "元,請支付。");
            //The part of change
            System.out.println("請輸入您支付的金額");
            int give = sca.nextInt();
            //make sure give>=need
            if (give < moneyall) {
                System.out.println("錢不夠的啦，您是第" + i + "位客人");
            } else {
                int back = give - moneyall;
                int z = back / 1000;
                int y = give % 1000;
                int a = y / 500;
                int b = give % 500;
                int c = b / 100;
                int d = b % 100;
                int e = d / 50;
                int f = d % 50;
                int g = f / 10;
                int h = f % 10;
                int u = h / 5;
                int j = h % 5;
                System.out.println("您是第" + i + ("位客人"));
                System.out.println("需找1000元" + z + "個");
                System.out.println("需找500元" + a + "個");
                System.out.println("需找100元" + c + "個");
                System.out.println("需找50元" + e + "個");
                System.out.println("需找10元" + g + "個");
                System.out.println("需找5元" + u + "個");
                System.out.println("需找1元" + j + "個");
            }

        }
    }
}
