package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {

        String one,two,three;
        File file = new File("3.strings");
        Scanner temp = new Scanner(file);

      temp.useDelimiter("\"*\"");
         temp.skip(" ");
       // temp.skip("\\ \"");
        //temp.findInLine("\"");
        one = temp.next();

        two = temp.next();

        three = temp.next();


        System.out.printf("Strings: %s , %s , %s \n", one, two, three);


        int find = comp.compare(one, two, three);

        if (find == 1)
        {
            System.out.printf("\"%s\" is not the same\n", one);
        }
        else if(find == 2){
            System.out.printf("\"%s\" is not the same\n", two);
        }
        else if (find == 3 )
        {
            System.out.printf("%s is not the same\n", three);
        }




    }

}
