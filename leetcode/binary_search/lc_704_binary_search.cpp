#include <vector>

/**
 * https://leetcode.com/problems/binary-search/description/
 *
 * Tine complexity: O(log(n)) where n = length of nums
 * Space complexity: O(1)
 */
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        // init our left and right pointers
        int left = 0;
        int right = nums.size()-1;

        // loop as long as the pointers don't overlap past one another
        while (left <= right) {
            // compute the middle index pointer
            int middle = (left + right) / 2;

            // if the middle number is the target, then return the index
            if (nums[middle] == target) {
                return middle;
            }

            // otherwise, if the target is larger than the middle number
            // update our left pointer to be past the middle pointer
            if (target > nums[middle]) {
                left = middle + 1;
            // else the target is smaller than the middle number
            // update our right pointer to be before the middle pointer.
            } else {
                right = middle - 1;
            }
        }

        // if the number is not found, return -1
        return -1;
    }
};
