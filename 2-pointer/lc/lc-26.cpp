// LeetCode 26: remove-duplicates-from-sorted-array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include "../../using.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        // ptr1, ptr2, unique count, size of the array
        int i = 0, j = 1, u = 1, n = nums.size();

        // iterate through the array or vector, will fix i on the unique elements & j will iterate through the array to find duplicates
        // at start of an array, as the list isn't empty, we have at least one unique element, so we can start with u = 1 
        while (i < n && j < n) {

            // case-1: if the elements are equal, we will just move j to the next element
            if (nums[i] == nums[j]) {
                j++;
            } 
            
            // case-2: if the elements are not equal, we will move i to the next element and update the value of nums[i] to nums[j], and increment u
            else {
                i++;
                nums[i] = nums[j];
                u++;
                j++;
            }
        }
        return u;
    }

/*
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        // ptr1, ptr2, unique count, size of the array
        int i = 0, j = 1, u = 1, n = nums.size();

        // unlike the previous solution, we will do is add another counter k which stores the next unique element's index
        // and we will update the value of nums[k] to nums[j] when we find a unique element, and increment k, u & j skipping
        // the duplicates
        int k = 1;
        while (i < n && j < n) {

            // case-1: if the elements are equal, we will just move j to the next element
            if (nums[i] == nums[j]) {
                j++;
            } 
            
            // case-2: if the elements are not equal, firstly we will update k to that index, then we will move i to the next 
            // unique element and update the value of nums[i] to nums[j], and increment u, k & j
            else {
                k = j;
                i++;
                nums[i] = nums[j];
                u++;
                j++;
            }
        }
        return u;
    }
*/

};