class Solution {
public:
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    bool isReachable(int targetX, int targetY) {
        int x = targetX;
        int y = targetY;
        while(x && x % 2 == 0) x /= 2;
        while(y && y % 2 == 0) y /= 2;
        return gcd(x, y) == 1;
    }
};
