/*
 * For this question, we know for sure that a sequence is either a b c or a c b. Therefore, we can enumerate all the 
 * position and assume that this position is the beginning of a sequence of a b c or a c b. Now what we have
 * to obtain from this sequence is how many a b and c are in sections a b and c. After we obtain that, we just need to 
 * figure out the minimum swaps in this specific sequence. It is obvious that the minimum steps requires you to switch
 * the a in b with the b in a, the a in c with the c in a and so on. However, after that, we still might need to do 
 * additional switches. An easy solution to figure out this number is to make the number of none a in section a plus 
 * the number of none b in section b subtract by the minimum of a in b and b in a. This equation works because by switching
 * all the none a in a, a only has a, and we may assume that b are sent to section b and c are sent to section c. same thing
 * with adding all none b in section b. We subtract by the minimum of a in b and b in a because as I said we can save
 * up moves by moving the b in a to b, and in the same time move the a in b to a. The maximum steps we can safe is
 * the minimum between a in b and b in a. After obtaining that, we can just print the minimum steps in the calculations.
 * 
 */

#include <iostream>
#define int long long
#define endl "\n"
using namespace std;
const int INF = 4e9;
string s;
int n, A, B, C;

int nums[4][4], nums2[4][4];

void update(int pos) {
    int i = A + pos - 1;
    if (s[i] == 'A') {
        nums[1][1]++;
    } else if (s[i] == 'B') {
        nums[1][2]++;
    } else {
        nums[1][3]++;
    }
    i = pos - 1;
    if (s[i] == 'A') {
        nums[1][1]--;
    } else if (s[i] == 'B') {
        nums[1][2]--;
    } else {
        nums[1][3]--;
    }
    i = A + B + pos - 1;
    if (s[i] == 'A') {
        nums[2][1]++;
    } else if (s[i] == 'B') {
        nums[2][2]++;
    } else {
        nums[2][3]++;
    }
    i = A + pos - 1;
    if (s[i] == 'A') {
        nums[2][1]--;
    } else if (s[i] == 'B') {
        nums[2][2]--;
    } else {
        nums[2][3]--;
    }

    i = A + B + C + pos - 1;

    if (s[i] == 'A') {
        nums[3][1]++;
    } else if (s[i] == 'B') {
        nums[3][2]++;
    } else {
        nums[3][3]++;
    }

    i = A + B + pos - 1;

    if (s[i] == 'A') {
        nums[3][1]--;
    } else if (s[i] == 'B') {
        nums[3][2]--;
    } else {
        nums[3][3]--;
    }
}

void update2(int pos) {
    int i = A + pos - 1;
    if (s[i] == 'A') {
        nums2[1][1]++;
    } else if (s[i] == 'B') {
        nums2[1][3]++;
    } else {
        nums2[1][2]++;
    }
    i = pos - 1;
    if (s[i] == 'A') {
        nums2[1][1]--;
    } else if (s[i] == 'B') {
        nums2[1][3]--;
    } else {
        nums2[1][2]--;
    }
    i = A + C + pos - 1;
    if (s[i] == 'A') {
        nums2[2][1]++;
    } else if (s[i] == 'B') {
        nums2[2][3]++;
    } else {
        nums2[2][2]++;
    }
    i = A + pos - 1;
    if (s[i] == 'A') {
        nums2[2][1]--;
    } else if (s[i] == 'B') {
        nums2[2][3]--;
    } else {
        nums2[2][2]--;
    }

    i = A + B + C + pos - 1;

    if (s[i] == 'A') {
        nums2[3][1]++;
    } else if (s[i] == 'B') {
        nums2[3][3]++;
    } else {
        nums2[3][2]++;
    }

    i = A + C + pos - 1;

    if (s[i] == 'A') {
        nums2[3][1]--;
    } else if (s[i] == 'B') {
        nums2[3][3]--;
    } else {
        nums2[3][2]--;
    }
}

signed main() {
    cin >> s;
    n = s.size();
    s += s;
    s = '@' + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'A') A++;
        else if (s[i] == 'B') B++;
        else C++;
    }
    int ans = INF;
    string res;

    for (int i = 1; i <= A; i++) {
        if (s[i] == 'A') {
            nums[1][1]++;
        } else if (s[i] == 'B') {
            nums[1][2]++;
        } else {
            nums[1][3]++;
        }
    }
    for (int i = A + 1; i <= A + B; i++) {
        if (s[i] == 'A') {
            nums[2][1]++;
        } else if (s[i] == 'B') {
            nums[2][2]++;
        } else {
            nums[2][3]++;
        }
    }
    for (int i = A + B + 1; i <= n; i++) {
        if (s[i] == 'A') {
            nums[3][1]++;
        } else if (s[i] == 'B') {
            nums[3][2]++;
        } else {
            nums[3][3]++;
        }
    }


    for (int i = 1; i <= A; i++) {
        if (s[i] == 'A') {
            nums2[1][1]++;
        } else if (s[i] == 'B') {
            nums2[1][3]++;
        } else {
            nums2[1][2]++;
        }
    }
    for (int i = A + 1; i <= A + C; i++) {
        if (s[i] == 'A') {
            nums2[2][1]++;
        } else if (s[i] == 'B') {
            nums2[2][3]++;
        } else {
            nums2[2][2]++;
        }
    }
    for (int i = A + C + 1; i <= n; i++) {
        if (s[i] == 'A') {
            nums2[3][1]++;
        } else if (s[i] == 'B') {
            nums2[3][3]++;
        } else {
            nums2[3][2]++;
        }
    }

    for (int i = 1; i <= n + 1; i++) {
        ans = min(ans, nums[2][1] + nums[2][3] + nums[1][2] + nums[1][3] - min(nums[1][2], nums[2][1]));
        ans = min(ans, nums2[3][1] + nums2[3][2] + nums2[1][2] + nums2[1][3] - min(nums2[1][3], nums2[3][1]));
        update(i + 1);
        update2(i + 1);
    }
    cout << ans << endl;
    return 0;
}
