/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.firsttry;

/*
 *
 * @author Calvin Wan
 */
import java.util.Scanner;

public class CMSquestion {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        //36->24
        Scanner sca = new Scanner(System.in);
        //分段准考證輸入
        /*System.out.println("請輸入您的准考證號碼前兩碼如：1214取12，0912取9，");
        int room = sca.nextInt();
        System.out.println("請輸入您的准考證號碼前兩碼如：1214取14，1204取4，");
        int num= sca.nextInt();
        int number = room*36+num;
        int trueroom = number/24;
        int truenumber = number%24;
        System.out.println("您的試場為"+trueroom+"號試場，您的座號為"+truenumber+"號");*/

        //完整准考證輸入
        System.out.println("請輸入您的准考證號碼");
        int id = sca.nextInt();
        int oldroom = id / 100;
        int oldnum = id - oldroom * 100;
        int act = oldroom * 36 + oldnum;12
        int newroom = act / 24;
        int newnumber = act % 24;
        System.out.println("您的試場為" + newroom + "號試場，您的座號為" + newnumber + "號");

    }

}
