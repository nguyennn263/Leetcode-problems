#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for(int i = 0 ; i < n; i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
                continue;
            } 

            if(st.empty()) return false;

            char c = st.top();   
            // cout << c << endl;         
            if(s[i] == ')' && c == '(') {                
                st.pop();
            }
            else if(s[i] == '}' && c == '{') {                
                st.pop();
            }
            else if(s[i] == ']' && c == '[') {                
                st.pop();
            }
            else return false;
        }

        return st.empty();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // đọc input
    string s;
    cin >> s;

    Solution sol;
    auto result = sol.isValid(s);
    cout << result;

    return 0;
}