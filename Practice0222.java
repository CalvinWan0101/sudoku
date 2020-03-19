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
public class Practice0222 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        /*The best one
        Scanner sca = new Scanner(System.in);
        System.out.println("請輸入你的座號");
         int number = sca.nextInt();
         int a =number%3;
         int b =number/3;
         System.out.println("請坐到第"+a+"排第"+b+"列");*/

//if -else  practice
/* System.out.println("請輸入你的座號");
        int number=sca.nextInt();
        int a=number%3;
if (a== 1) {
            System.out.println("請坐到第1排");
        }
        else if (a == 2) {
                    System.out.println("請坐到第2排");
                }
        else {
                    System.out.println("請坐到第3排");
                }      */
//switch practice
/*System.out.println("請輸入你的座號");
Scanner sca=new Scanner(System.in);        
int number=sca.nextInt();
        int a=number%3;
        int b=number/3;
        switch (a)
        {case 1 : 
            System.out.println("請坐到第1排"+"第"+b+"列");
            break;
        case 2: 
            System.out.println("請坐到第2排"+"第"+b+"列");
            break;
        case 0 :
            System.out.println("請坐到第3排"+"第"+b+"列");
            break;
        default:
            System.out.println("哦哦哦，好像出問題了哦");
        
        }*/
//Mask question
        /*Scanner sca = new Scanner(System.in);
        System.out.println("請輸入您的西元出生年，如2003");
         int number = sca.nextInt();
         int a=2020-number;
         int b=13;
         if (a<b)
         {System.out.println("您的年齡為"+a+"，判斷為兒童，您可以購買4個兒童用口罩");}
         else
             System.out.println("您的年齡為"+a+"，判斷為非兒童，您不能購買口罩");}*/
//Mask question boolean practice
        /*Scanner sca = new Scanner(System.in);
        System.out.println("請輸入您的西元出生年，如2003");
         int number = sca.nextInt();
         int a=2020-number;
         int b=13;
         boolean year;
         year = a<b?true:false;
         if (year)
         {System.out.println("您的年齡為"+a+"，判斷為兒童，您可以購買4個兒童用口罩");}
         else
             System.out.println("您的年齡為"+a+"，判斷為非兒童，您不能購買口罩");}*/
        //WuHan Coronavirus the right to come back Taiwan boolean practice
        /* Scanner sca = new Scanner(System.in);
        System.out.println("您是否為母親？，輸入1為母親，輸入2則為非母親");
        boolean mother;
        int number = sca.nextInt();
        mother = number == 1 ? true : false;
        if (mother) {
            System.out.println("您是否有帶小孩，輸入1表示有，輸入2表示沒有");
        } else {
            System.out.println("Maybe stay in China is not a bad idea");
        }
        int kid = sca.nextInt();
        boolean son;
        son = kid == 1 ? true : false;
        if (son) {
            System.out.println("請輸入您的西元出生年，如2003");
        } else {
            System.out.println("Maybe stay in China is not a bad idea");
        }
        int year = sca.nextInt();
        int a = 2020 - year;
        int b = 13;
        boolean y;
        y = a < b ? true : false;
        if (y) {
            System.out.println("Taiwan will be your next station");
        } else {
            System.out.println("您的小孩為"+a+"歲，不符合回台資格 "+ "So maybe stay in China is not a bad idea");
        }*/
        //WuHan Coronavirus the right to come back Taiwan boolean practice  esayone
        //wait to be down、
//for loop practice 1
        /*int a;
        int people = 0;
        for (a = 0; a < 400; a += 2) {
            people++;
            if (people > 200) {
                break;
            }
        }

        System.out.println("可以賣" + people + "個人");*/
 /*Scanner sca = new Scanner(System.in);
        int i;
        int stock = 100;
        for (i = 1; i < 100; i++) {
            System.out.println("請輸入所購買口罩的數量");
            int buy = sca.nextInt();
            int money = buy * 5;
           if (stock<buy){buy=stock;System.out.println("哦吼吼，庫存好像不太夠哦");}
            stock = stock - buy;
            System.out.println("第" + i + "個人買" + " 庫存=" + stock + "錢錢=" + money);
            if (stock <= 0) {
                break;
            }
        }int AllMoney=100*5;
        System.out.println("總共" + i + "個人買,總金額為"+AllMoney+"元");*/
//While loop practice
        /*int stock = 100;
        int i = 0;
        Scanner sca = new Scanner(System.in);
        while (stock >= 0) {
            System.out.println("請輸入所要購買的數量");
            int buy = sca.nextInt();
            if (buy > stock) {
                buy = stock;
                System.out.println("哦哦哦好像貨不太夠哦,我們只能賣你" + stock + "個口罩");
            }
            stock = stock - buy;
            i++;
            int money = buy* 5;
            System.out.println("第" + i + "個客人" + "購買數量" + buy + " 庫存" + stock + " 收益" + money);
            if (stock == 0) {
                break;
            }
        }
        int AllMoney = 100 * 5;
        System.out.println("商品全數售出！總收益為" + AllMoney + "元，總顧客為" + i + "人");*/
        //do loop practice
        int stock = 100;
        int i = 0;
        Scanner sca = new Scanner(System.in);
        do {
            System.out.println("請輸入所要購買的數量");
            int buy = sca.nextInt();
            if (buy > stock) {
                buy = stock;
                System.out.println("哦哦哦好像貨不太夠哦,我們只能賣你" + stock + "個口罩");
            }
            stock = stock - buy;
            i++;
            int money = buy * 5;
            System.out.println("第" + i + "個客人" + "購買數量" + buy + " 庫存" + stock + " 收益" + money);
            if (stock == 0) {
                break;
            }
        } while (stock >= 0);
        int AllMoney = 100 * 5;
        System.out.println("商品全數售出！總收益為" + AllMoney + "元，總顧客為" + i + "人");
    }
}
