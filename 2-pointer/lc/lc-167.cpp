// LeetCode 167: 2 Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// 1-Indexed Array
// Time Complexity: O(N)
// Space Complexity: O(1)
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

/*
Complexity Calculation:
- Time Complexity: O(N)
  - Pointers left (starts 0) and right (starts N-1) move toward each other.
  - At every step, either left increments or right decrements.
  - Loop executes at most N times -> Total Time = O(N).

- Space Complexity: O(1)
  - Only uses scalar variables (left, right, size, sum) and a 2-element result vector.
  - No auxiliary data structures proportional to input size -> Auxiliary Space = O(1).
*/