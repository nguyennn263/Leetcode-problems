#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int cursum = 0;
        for(int i = 0 ; i < n ;i++) {
            sum += nums[i];
            cursum += (i+1) * nums[i];
        }
        int res = cursum;
        for(int i = 0 ; i < n ; i++){
            cursum = cursum - sum + n * nums[i];
            res = max(res , cursum); 
        }

        // cout << res - sum;
        return res -sum;
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
    auto result = sol.maxRotateFunction(nums);
    cout << result;

    return 0;
}