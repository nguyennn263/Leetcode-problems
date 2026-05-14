#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> res;
        nums.insert(nums.begin(),-12);
        for(int i = 1 ; i < nums.size(); i++){
            if(mp[target - nums[i]] != 0) {
                res.push_back(i-1);
                res.push_back(mp[target - nums[i]] -1);
                return res;
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // đọc input
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int &x : nums) cin >> x;

    Solution sol;
    auto result = sol.twoSum(nums, target);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}