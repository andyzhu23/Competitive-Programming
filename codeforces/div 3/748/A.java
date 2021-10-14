import java.util.*;
import java.io.*;
 
public class A {
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
    static void solve() throws IOException{
        long a = readInt();
        long b = readInt();
        long c = readInt();
        long ans1 = Math.max(Math.max(b, c) - a + 1, 0);
        long ans2 = Math.max(Math.max(a, c) - b + 1, 0);
        long ans3 = Math.max(Math.max(b, a) - c + 1, 0);
        System.out.println(ans1 + " " + ans2 + " " + ans3);
    }
}
