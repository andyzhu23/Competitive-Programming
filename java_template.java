import java.util.*;
import java.io.*;

public class Main{
    static IO io = new IO();
    public static void main(String[] args) throws IOException {
        
    }
}

class IO {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    String next() throws IOException {
        while(st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    int readInt() throws IOException {
        return Integer.parseInt(next());
    }
    String readString() throws IOException {
        return next();
    }
    char readChar() throws IOException {
        return next().charAt(0);
    }
    short readShort () throws IOException {
        return Short.parseShort(next());
    }
    double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
    long readLong () throws IOException {
        return Long.parseLong(next());
    }
    String readLine () throws IOException {
        return br.readLine().trim();
    }
}
