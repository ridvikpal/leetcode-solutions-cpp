#include <vector>


/**
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * Time complexity: O(log(n)) where n = length of nums
 * Space complexity: O(1)
 */
class Solution {
public:
    // we will use a modified binary search algorithm where we determine
    // which half of the array is sorted and which is not
    int findMin(std::vector<int>& nums) {
        // init our standard left and right pointers for binary search
        int left = 0;
        int right = nums.size()-1;

        // init the minimum number (as per leetcode, max(nums) = 5000)
        int minNum = 5001;

        // standard binary search while loop
        while (left <= right) {
            // get the middle number, and update the minimum number if required
            int middle = (left+right) / 2;
            minNum = std::min(nums[middle], minNum);

            // first check if the section of the array we are
            // searching is fully sorted (left to right, ascending)
            // if so, then we know the minimum number is the left number
            // so update the minimum number and then stop searching
            if (nums[right] > nums[left]) {
                minNum = std::min(nums[left], minNum);
                break;
            // else check if the section to the left of the middle pivot
            // is sorted (left to middle, ascending)
            // if so, then we know the minimum number will be in the right section
            // so search the right section by updating the left pointer
            } else if (nums[middle] >= nums[left]) {
                left = middle + 1;
            // else we know the section to the right of the middle pivot
            // is sorted (middle to right, ascending)
            // so we know the minimum number will be in the left section
            // so search the left section by updating the right pointer.
            } else {
                right = middle - 1;
            }
        }

        // finally, return the minimum number
        return minNum;
    }
};
