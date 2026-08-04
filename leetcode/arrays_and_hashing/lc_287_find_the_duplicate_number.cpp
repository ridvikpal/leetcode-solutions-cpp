#include <vector>

/**
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * Time complexity: O(n) where n = length of nums
 * Space complexity: O(1)
 */
class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        // we will use a slow and fast pointer technique
        // similar to linked lists
        // we can treat each value as referencing (pointing to)
        // the next value in the array
        int slowPointer = 0;
        int fastPointer = 0;

        // we will loop until the slow and fast pointer meet at the same index
        do {
            slowPointer = nums[slowPointer];
            fastPointer = nums[nums[fastPointer]];

        } while (slowPointer != fastPointer);

        // then we will use a second slow pointer and loop until they meet again
        int slowPointer2 = 0;

        do {
            slowPointer = nums[slowPointer];
            slowPointer2 = nums[slowPointer2];
        } while (slowPointer != slowPointer2);

        // now, the slow pointer refers to the duplicate value, so we can return it
        return slowPointer;
    }
};
