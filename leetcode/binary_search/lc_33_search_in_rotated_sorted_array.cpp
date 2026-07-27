#include <vector>

/**
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * Time complexity: O(log(n)) where n = length of nums
 * Space complexity: O(1)
 */
class Solution {
public:
    // we will use a modified binary search algorithm where we determine
    // which half of the array is sorted and which is not
    int search(std::vector<int>& nums, int target) {
        // init the standard left and right binary search pointers
        int left = 0;
        int right = nums.size()-1;

        // standard binary search while loop
        while (left <= right) {
            // get the middle index, and return it if it points to the target
            int middle = (left+right) / 2;
            if (nums[middle] == target) {
                return middle;
            }

            // first check if we are searching the sorted section of the array
            // if we are, then we will perform a standard binary search left/right update
            // because all subsequent sections of the array to search will also be sorted
            if (nums[right] > nums[left]) {
                if (target > nums[middle]) {
                    left = middle+1;
                } else {
                    right = middle-1;
                }
            // second check if the left side is the sorted section of the array
            } else if (nums[middle] >= nums[left]) {
                // then check if this sorted left section contains our target
                // if it does, then search this sorted left side by updating the right pointer
                if ((target >= nums[left]) && (target < nums[middle])) {
                    right = middle-1;
                // else this sorted left side doesn't contain our target
                // so search the unsorted right side by updating the left pointer
                } else {
                    left = middle+1;
                }
            // finally this means the right side is the sorted section of the array
            } else {
                // then check if this sorted right section contains our target
                // if it does, then search this sorted right side by updating the left pointer
                if ((target > nums[middle]) && (target <= nums[right])) {
                    left = middle+1;
                // else this sorted right side doesn't contain our target
                // so search the unsorted left side by updating the right pointer
                } else {
                    right = middle-1;
                }
            }
        }

        // finally, if we never find the target, return -1
        return -1;
    }
};
