package com.company;
/**
 * Created by matt on 10/30/2014.
 */
public  class comp {
    public static int compare(String one, String two, String three) {

        if (one.equals("Not")) {
            return 3;
        }
        else if (two.equals(three)) {
            return 1;
        }
        else if (three.equals(one)) {
            return 2;
        }
        else {
            return 0;
        }
    }
}

