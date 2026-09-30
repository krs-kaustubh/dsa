// LeetCode 80: Remove Duplicates from Sorted Array II
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// helped by AI
#include "../../using.h"

class Solution {
public:
    // This problem is similar to LeetCode 23, but here we have to print the unique elements at most twice if present 
    int removeDuplicates(vector<int>& nums) {
    
        if (nums.size() == 0) {
            return 0;
        }

        // i: write pointer (last valid written index)
        // j: read pointer (scans array)
        // u: count of current element written so far
        int i = 0, j = 1, u = 1, n = nums.size();

        while (j < n) {
            if (nums[i] == nums[j]) {
                if (u < 2) {
                    i++;
                    nums[i] = nums[j];
                    u++;
                }
                // u >= 2: skip duplicate, do not write
            } else {
                // New unique element found: reset count to 1
                i++;
                nums[i] = nums[j];
                u = 1;
            }
            j++; // Always advance read pointer
        }

        return i + 1;
    }
};