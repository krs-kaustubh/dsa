// LeetCode 1: Two Sum
// https://leetcode.com/problems/two-sum/
// 0-Indexed Array
#include "../../using.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0, i = 0, j = 0, size = nums.size();
        vector<int> pair = {};
        
        for (i = 0; i < size; i++) {
            for (j = i + 1; j < size; j++) {
                sum = nums[i] + nums[j];

                if (sum == target) {
                    pair.push_back(i);
                    pair.push_back(j);
                    break;
                }
            }
        }
        return pair;
    }
};