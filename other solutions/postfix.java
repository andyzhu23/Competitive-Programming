/*
 * Author: Andy Zhu
 * @date    2022-07-25 08:17:06
 * @version 1.0.0
 */

import java.io.*;
import java.util.*;

public class postfix {
    static BufferedReader br; static StringTokenizer st;
    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static short readShort () throws IOException {
        return Short.parseShort(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
    static char readChar () throws IOException {
        return next().charAt(0);
    }
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
    //----------------End of Template----------------
    public static void main(String[] args) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        String[] in = br.readLine().split(" ");
        ArrayList<Double> a = new ArrayList<>();
        for(var x : in) {
            if(x.equals("+")) {
                double tmp = a.remove(a.size() - 1) + 
                a.remove(a.size() - 1);
                a.add(tmp);
            } else if(x.equals("-")) {
                double u = a.remove(a.size() - 1);
                double y = a.remove(a.size() - 1);
                a.add(y - u);
            } else if(x.equals("*")) {
                double tmp = a.remove(a.size() - 1) *
                a.remove(a.size() - 1);
                a.add(tmp);
            } else if(x.equals("/")) {
                double u = a.remove(a.size() - 1);
                double y = a.remove(a.size() - 1);
                a.add(y / u);
            } else if(x.equals("%")) {
                double u = a.remove(a.size() - 1);
                double y = a.remove(a.size() - 1);
                a.add(y % u);
            } else if(x.equals("^")) {
                double u = a.remove(a.size() - 1);
                double y = a.remove(a.size() - 1);
                a.add(Math.pow(y, u));
            } else a.add(Double.parseDouble(x));
        }
        System.out.printf("%.1f\n", a.get(0));
        br.close();
    }
}
