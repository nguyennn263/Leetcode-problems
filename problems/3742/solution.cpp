#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cal(int x){
        if (x == 0) return 0;
        if (x == 1) return 1;
        if (x == 2) return 1;
        return x;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector< vector<vector<int> > > dp (n + 3, vector< vector<int> > (m + 3, vector<int> (k + 5, -INT_MAX)));
        dp[0][0][0] = 0;
        
        for (int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                for(int t = 0 ; t <= k ; t++){
                    if(dp[i][j][k] == -INT_MAX) continue;
                    if(i+1 < n){
                        int cost = cal(grid[i+1][j]);
                        int value =  grid[i+1][j];
                        if(t+cost <= k){
                            dp[i+1][j][t+cost] = max(dp[i+1][j][t+cost], dp[i][j][t] + value);
                        } 
                    }
                    if(j+1 < m){
                        int cost = cal(grid[i][j+1]);
                        int value =  grid[i][j+1];
                        if(t+cost <= k){
                            dp[i][j+1][t+cost] = max(dp[i][j+1][t+cost], dp[i][j][t] + value);
                        } 
                    }

                }
            }
        }
        int res = -1;
        for (int t = 0 ; t <= k ; t++){
            // cout << dp[n-1][m-1][t] << endl;
            // cout << dp[0][0][t] << endl;
            // cout << dp[0][1][t] << endl;
            // cout << dp[1][0][t] << endl;
            // cout << endl;
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
    vector<vector<int>> nums(n, vector<int> (m));
    for (vector<int> &num : nums)
        for (int &x : num) cin >> x;

    Solution sol;
    auto result = sol.maxPathScore(nums, target);
    cout << result;


    return 0;
}