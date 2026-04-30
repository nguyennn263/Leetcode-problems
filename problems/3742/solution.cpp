#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cal(int x){
        if (x == 0) return 0;
        if (x == 1) return 1;
        if (x == 2) return 1;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp (n + 1, vector<int> (m +1 , vector<int> (k + 5, -k)));
        for (int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if (i == 0 && j == 0) dp[i][j] = 0;
                for(int t = 0 ; t <= k ; t++){
                    int cost = cal(grid[i][j]);
                    int value =  grid[i][j];
                    if(t+cost <= k){
                        dp[i+1][j][t+cost] = max(dp[i+1][j][t + cost], dp[i][j][t] + value);
                        dp[i][j+1][t+cost] = max(dp[i][j+1][t + cost], dp[i][j][t] + value);
                    } 
                }
            }
        }
        int res = -1;
        for (int t = 0 ; t <= k ; t++){
            res = max(res , dp[n-1][m-1][t]);
        }
        return  res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // đọc input
    int n, m, target;
    cin >> n >> m >> target;
    vector<int> nums(n, vector<int> (m));
    for (vector<int> &num : nums)
        for (int &x : num) cin >> x;

    Solution sol;
    auto result = sol.twoSum(nums, target);
    cout << result;


    return 0;
}