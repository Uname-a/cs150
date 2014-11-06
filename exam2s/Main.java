package com.company;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {

        double[] First = new double[3];
        double[] Second = new double[3];
        double first,second;


        Scanner keyboard;

        System.out.printf("First set, First number: ");
        keyboard = new  Scanner(System.in);
        First[0] = keyboard.nextDouble();
        System.out.printf("\n");
        System.out.printf("First set, Second number: ");
        keyboard = new  Scanner(System.in);
        First[1] = keyboard.nextDouble();
        System.out.printf("\n");
        System.out.printf("First set, Third number: ");
        keyboard = new  Scanner(System.in);
        First[2] = keyboard.nextDouble();
        System.out.printf("\n");

        first = support.math(First);

        System.out.printf("For this set, the variance is %f\n", first);

        System.out.printf("Second set, First number: ");
        keyboard = new  Scanner(System.in);
        Second[0] = keyboard.nextDouble();
        System.out.printf("\n");
        System.out.printf("Second set, Second number: ");
        keyboard = new  Scanner(System.in);
        Second[1] = keyboard.nextDouble();
        System.out.printf("\n");
        System.out.printf("Second set, Third number: ");
        keyboard = new  Scanner(System.in);
        Second[2] = keyboard.nextDouble();
        System.out.printf("\n");

        second = support.math(Second);
        System.out.printf("For this set, the variance is %f\n",second);

         double comp = support.compare(first,second);

        if (comp == 1) {
            System.out.printf("The first set has a larger variance\n" );
        }
        else if (comp == 2) {
            System.out.printf("The second set has a larger variance\n");
        }
        else {
            System.out.printf("The sets have the same variance\n");
        }

    }

}
