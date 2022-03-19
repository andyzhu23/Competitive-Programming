import java.util.*;
import java.io.*;

public class J2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int ans = 0;
        for(int i = n;i<=m;++i) {
            String s = i + "";
            boolean flag = true;
            for(int j = 0;j<s.length();++j) {
                char a = s.charAt(j);
                char b = s.charAt(s.length() - j - 1);
                if(!((a == b && (a == '1' || a == '0' || a == '8')) || ((a == '6' && b == '9') || (a == '9' && b == '6')))) {
                    flag = false;
                } 
            }
            if(flag) ans++;
        }
        System.out.println(ans);
    }
}