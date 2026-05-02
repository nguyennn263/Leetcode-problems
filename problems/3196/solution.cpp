#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();

        vector< vector<long long> > dp (n+10, vector<long long> (3, -1e18+1));
        dp[0][0] = nums[0];

        for(int i = 1 ; i < n ; i++){
            dp[i][0] = max(dp[i-1][0] + nums[i] , dp[i-1][1] + nums[i]);                
            dp[i][1] = dp[i-1][0] - nums[i];  
            // cout << i << " "<< dp[i][0] << " " << dp[i][1] << endl;             
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // đọc input
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &x : nums) cin >> x;

    Solution sol;
    auto result = sol.maximumTotalCost(nums);
    cout << result;

    return 0;
}