// LeetCode 167: 2 Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// 1-Indexed Array
#include "../../using.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, size = numbers.size(), sum = 0;
        int right = size - 1;
        vector<int> pair = {};

        while (left < right) {
            sum = numbers[left] + numbers[right];

            // case-1: sum = target
            if (sum == target) {
                pair.push_back(left + 1);
                pair.push_back(right + 1);
                break;
            } 

            // case-2: sum < target
            else if (sum < target) {
                left++;
            }

            // case-3: sum > target
            else {
                right--;
            }
        }

        return pair;
    }
};