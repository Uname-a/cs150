package com.company;
import java.util.*;
public class Main {

    public static void main(String[] args) {
	    int[] array;
        array = new int[3];

        System.out.println("first integer?");
        Scanner keyboard = new  Scanner(System.in);
        array[0] = keyboard.nextInt();
        System.out.println("second integer? ");
        keyboard =  new Scanner(System.in);
        array[1] = keyboard.nextInt();
        System.out.println("third integer? ");
        keyboard =  new Scanner(System.in);
        array[2] = keyboard.nextInt();

        System.out.println(array[0]);
        System.out.println(array[1]);
        System.out.println(array[2]);

        int swap;
        int four;
        System.out.println("fourth integer? ");
        keyboard =  new Scanner(System.in);
        four = keyboard.nextInt();
        swap = array[2];
        array[2] = four;
        four = array[1];
        array[1] = swap;
        array[0] = four;

        System.out.println("Rearanged array: ");

        System.out.println(array[0]);
        System.out.println(array[1]);
        System.out.println(array[2]);


    }
}
