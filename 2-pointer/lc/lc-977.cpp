// LeetCode 977: Squares of a Sorted Array
// https://leetcode.com/problems/squares-of-a-sorted-array/
#include "../../using.h"

// method-1: Mine
/* class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        // first we will check if the array is empty or not. Then if the 1st index is >= 0, if it is just sq the given array as it is
        if (nums.size() == 0) {
            return {};
        }

        int n = nums.size();
        vector<int> ans(n);

        if (nums[0] >= 0) {
            for (int i = 0; i < n; i++) {
                ans[i] = nums[i] * nums[i];
            }
            return ans;
        }

        // if the first index is < 0, we will use 2 pointers approch
        // firstly we send a pointer to the last negative number then we send the 2nd ptr to the very nxt element
        // sqring elements at tht index and comparing them, the lesser one get's pushed to the ans vector & ptr are moved accordingly
        
        // another condition to check, if the last element is also < 0, we just sq and reverse 
        if (nums[n - 1] < 0) {
            for (int i = n - 1; i >= 0; i--) {
                ans[n - 1 - i] = nums[i] * nums[i];
            }
            return ans;
        }

        int p1 = 0, p2 = 0;
        while (p1 < n && nums[p1] < 0) {
            p1++;
        } // now as p1 points to the 1st non-negative number. we give it's value to p2 & substract 1
        p2 = p1;
        p1 = p1 - 1;

        // comapring the sq of the elements at p1 & p2, lesser one gets pushed to ans vector & ptr are moved accordingly
        int i = 0;
        while (i < n) {
        if (p1 < 0) {
            ans[i] = nums[p2] * nums[p2++];
        } else if (p2 >= n) {
            ans[i] = nums[p1] * nums[p1--];
        } else if (nums[p1] * nums[p1] < nums[p2] * nums[p2]) {
            ans[i] = nums[p1] * nums[p1--];
        } else {
            ans[i] = nums[p2] * nums[p2++];
        }
        i++;
    }
        return ans;
    }
};
*/

// method-2: Optimized (singh suggested)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        // first we will check if the array is empty or not. Then if the 1st index is >= 0, if it is just sq the given array as it is
        if (nums.size() == 0) {
            return {};
        }

        int n = nums.size();
        vector<int> ans(n);

        // if the first index is >= 0, just square the given array as it is
            if (nums[0] >= 0) {
            for (int i = 0; i < n; i++) {
                ans[i] = nums[i] * nums[i];
            }
            return ans;
        }

        // if the last element is also < 0, we just sq and reverse
        if (nums[n - 1] < 0) {
            for (int i = n - 1; i >= 0; i--) {
                ans[n - 1 - i] = nums[i] * nums[i];
            }
            return ans;
        }

        // here we setup the 2 ptrs as it is (at extreme ends) & push the sq of greater one at end index of ans vector & move the ptr accordingly
        int p1 = 0, p2 = n - 1;
        
        while (p1 <= p2) {
            if (nums[p1] * nums[p1] > nums[p2] * nums[p2]) {
                ans[n - 1 - p2 + p1] = nums[p1] * nums[p1];
                p1++;
            } else {
                ans[n - 1 - p2 + p1] = nums[p2] * nums[p2];
                p2--;
            }
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sol.sortedSquares(nums);
    
    cout << "Sorted Squares: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}