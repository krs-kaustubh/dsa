// LeetCode 1: Two Sum
// https://leetcode.com/problems/two-sum/
// 0-Indexed Array
// Time Complexity: O(N^2)
// Space Complexity: O(1) (auxiliary)
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

/*
Complexity Calculation:
- Time Complexity: O(N^2)
  - Outer loop runs N times (i from 0 to N-1).
  - Inner loop runs (N - 1 - i) times: (N-1) + (N-2) + ... + 1 = N*(N-1)/2 iterations.
  - Constant time operations inside loop -> Total Time = O(N^2).

- Space Complexity: O(1) auxiliary
  - Only uses scalar variables (sum, i, j, size) and fixed 2-element output vector.
  - No dynamic scaling memory used -> Auxiliary Space = O(1).
*/