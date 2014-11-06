package com.company;
import java.util.*;
public class Main {

    public static void main(String[] args) {
	    double height;

        System.out.println("Drop height (meters)? ");
        Scanner keyboard = new  Scanner(System.in);
        height = keyboard.nextInt();
        height = height * 3.2808;

        System.out.printf("Podiatrically speaking, that's %f feet \n",height );
        System.out.printf("At the given height, velocity before impact is %f feet per second \n",Math.pow((2 * 32.185 * height),.5));


    }
}
