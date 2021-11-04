/*
 * Author: Andy Zhu
 * @date    2021-11-01 17:24:36
 * @version 1.0.0
 */

import java.io.*;
import java.util.*;

public class Victor_Makes_Banks {
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

    static long n;
    static int t, c, k;
    static int MOD = 1000000007;

    static class mat {
        long[][] a;
        int MOD;
        mat() {
            a = new long[104][104];
            MOD = 1000000007;
        }
        mat mul(mat other) {
            mat ans = new mat();
            for(int i = 1;i<=t + 1;++i) {
                for(int j = 1;j<=t + 1;++j) {
                    for(int k = 1;k<=t + 1;++k) {
                        ans.a[i][j] = (ans.a[i][j] + a[i][k] % MOD * other.a[k][j] % MOD) % MOD;
                    }
                }
            }
            return ans;
        }
    }
    static mat tmp;
    static mat fast_pow(mat a, long b) {
        if(b == 1) return a; 
        tmp = fast_pow(a, b >> 1); 
        if((b & 1) == 1) return (tmp.mul(tmp)).mul(a); 
        else return tmp.mul(tmp);
    }
    static mat init, b;
    public static void main(String[] args) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        n = readLong();
        k = readInt();
        t = readInt();
        c = readInt();
        if(n == 1) {
            System.out.println((c << 1) % MOD);
            return;
        }
        init = new mat();
        b = new mat();
        init.a[1][1] = c;
        b.a[1][1] = 1;
        for(int i = 1;i<=t;++i) {
            b.a[i][i + 1] = 1;
        }
        b.a[t + 1][1] = k;
        mat ans = fast_pow(b, n - 1).mul(init);
        long tot = ans.a[1][1];
        for(int i = 1;i<=t + 1;++i) {
            tot += ans.a[i][1];
            tot %= MOD;
        }
        System.out.println(tot);
        br.close();
    }
}
