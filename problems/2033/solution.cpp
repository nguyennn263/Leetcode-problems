#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> mp;
        for(unsigned int i = 0 ; i < grid.size(); i++){
            for(unsigned int j = 0; j < grid[0].size(); j++){
                mp.push_back(grid[i][j]);
                // cout << grid[i][j] << " "; 
            }
            // cout << "\n";
        }
        sort(mp.begin(), mp.end());
        int a = mp[mp.size()/2];
        int res = 0;
        // cout << a << endl;
        for(unsigned int i = 0 ; i < grid.size(); i++){
            for(unsigned int j = 0; j < grid[0].size(); j++){
                if(abs(grid[i][j] - a) % x) return -1;
                res += abs(grid[i][j] - a)/x;
            }
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // đọc input
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> nums(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> nums[i][j];
        }
    }

    Solution sol;
    auto result = sol.minOperations(nums, x);
    // for (int i : result) {
    //     cout << i << ' ';
    // }
    cout << result << '\n';

    return 0;
}