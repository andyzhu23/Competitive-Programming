import java.util.*;
import java.io.*;
 
public class D1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static String read() throws IOException{
        while(st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt() throws IOException {
        return Integer.parseInt(read());
    }
    static final int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    public static void main(String[] args) throws IOException{
        int t = readInt();
        while(t > 0) {
            solve();
            t--;
        }
    }
    static int gcd(int a, int b) {
        if(b == 0) return a;
        if(a == 0) return b;
        return gcd(b, a % b);
    }
    static void solve() throws IOException{
        int n = readInt();
        int[] a = new int[n + 1];
        int[] d = new int[n + 1];
        for(int i = 1;i<=n;++i) a[i] = readInt();
        for(int i = 1;i<n;++i) d[i] = a[i + 1] - a[i];
        int ans = Math.abs(d[1]);
        for(int i = 1;i<n;++i) ans = gcd(ans, Math.abs(d[i]));
        System.out.println(ans == 0 ? -1 : ans);
    }
}
