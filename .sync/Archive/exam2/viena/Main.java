package com.company;
import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner keyboard;
        int one,two,three;
        one = Integer.parseInt(args[0]);
        two = Integer.parseInt(args[1]);
        three = Integer.parseInt(args[2]);
        System.out.printf("Args: %d , %d ,%d \n", one, two, three);
        System.out.printf("Args plus one: %d, %d ,%d \n", one + 1, two + 1, three + 1);

        int find = order.order(one,two,three);
        if (find == 1)
        {
            System.out.printf("The numbers are in decending order\n");
        }
        else if(find == 2){
            System.out.printf("The numbers are in ascending order\n");
        }
        else if (find == 3 )
        {
            System.out.printf("The numbers are not in order\n");
        }



    }

}
