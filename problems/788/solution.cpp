#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    int trans(int c){
        if (c == 2) return 5;
        if (c == 5) return 2;
        if (c == 6) return 9;
        if (c == 9) return 6;
        if (c == 0 || c == 1|| c ==8) return c;
        return -1;
    }

    bool ck(int x){
        string n = to_string(x);
        int new_n = 0;
        for(unsigned int i = 0 ; i < n.size(); i++){
            int digit = int (n[i] - '0');
            int c = trans(digit);
            if (c == -1) return false;
            new_n = new_n * 10 + c;
        }

        return (new_n != x);         
    }

    int rotatedDigits(int n) {
        int res = 0;
        for(int i = 1 ; i <= n ; i++){
            // cout << i << " " << ck(i) << endl;
            res += ck(i);
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // đọc input
    int n;
    cin >> n;

    Solution sol;
    int result = sol.rotatedDigits(n);
    cout << result;

    return 0;
}