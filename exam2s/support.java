package com.company;
/**
 * Created by matt on 10/30/2014.
 */
public  class support {
    public static double math(double[] array)
    {
        double result;
        double m ;
        //array = new double[3];

        m = (array[0]+array[1] + array[2])/3;


      //  result = array[0] - m;
        result = ((((array[0]-m)*(array[0]-m))+((array[1]-m)* (array[1]-m)) +((array[2]-m)*(array[2]-m)))/3.0);


        return result;

    }


    public static double compare( double first, double second)
    {
        if (first > second)
        {
            return 1;
        }
        else if (first < second)
        {
            return 2;
        }
        else
        {return 0;}
    }
    }


