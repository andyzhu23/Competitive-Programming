
import java.math.*;
import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int MOD = 1000000007;
    static BigInteger n;
    static BigInteger one = new BigInteger("1");
    static BigInteger two = new BigInteger("2");
    public static void main(String[] args) throws IOException{
        String input = br.readLine();
        br.close();
        n = new BigInteger(input);
        mat matr = new mat();
        matr.a[1][1] = 1;
        matr.a[1][2] = 1;
        matr.a[2][1] = 1;
        matr.a[2][2] = 0;
        mat b = new mat();
        b.a[1][1] = 1;
        b.a[1][2] = 0;
        b.a[2][1] = 1;
        b.a[2][2] = 0;
        mat ans = fast_pow(matr, n.subtract(new BigInteger("2"))).multiply(b);
        System.out.println(ans.a[1][1]);
    }

    static mat fast_pow(mat a, BigInteger k){
        if(k.equals(one)) return a;
        mat tmp = fast_pow(a, k.divide(two));
        if(k.mod(two).equals(one)) return tmp.multiply(tmp).multiply(a);
        else return tmp.multiply(tmp);
    }

}

class mat {
    long [][] a = new long[3][3];
    static int MOD = 1000000007;
    public mat() {}

    public mat multiply(mat other){
        mat ans = new mat();
        for(int i = 1;i<=2;i++) {
            for(int j = 1;j<=2;j++) {
                for(int k = 1;k<=2;k++) {
                    ans.a[i][j] += this.a[i][k] * other.a[k][j] % MOD;
                    ans.a[i][j] %= MOD;
                }
            }
        }
        return ans;
    }
}
