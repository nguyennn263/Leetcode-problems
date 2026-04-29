#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        queue<int> st;
        vector<int> ck (n+1, 0);
        ck[0] = 1;
        st.push(0);
        int fathest = 0;
        while(!st.empty()){
            int v = st.front();
            st.pop();
            int start = max(v + minJump, fathest);
            int end = min(v + maxJump, n - 1);

            for(int j = start; j <= end; j++) {
                if(s[j] == '0') {
                    if(j == n - 1) return true;
                    st.push(j);
                }
            }
            fathest = end + 1;
        }

        return ck[n-1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // đọc input
    string s;
    int minjump, maxjump;
    cin >> s >> minjump >> maxjump;

    Solution sol;
    auto result = sol.canReach(s, minjump, maxjump);
    cout << result;

    return 0;
}