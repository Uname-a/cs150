package com.company;

/**
 * Created by matt on 10/30/2014.
 */
public class order {
    public static int order(int one, int two, int three)
    {
        if ( one >= two && two >= three && one > three)
        {
            return 1;
        }
        else if (three >= two && two >= one && three > one)
        {

            return 2;
        }
        else
        {

            return 3;
        }
    }
}
