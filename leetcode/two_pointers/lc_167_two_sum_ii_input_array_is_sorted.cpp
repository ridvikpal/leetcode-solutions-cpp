#include <vector>

/**
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * Time complexity: O(n) where n = length of numbers
 * Space complexity: O(1)
 */
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        // init the results vector
        std::vector<int> result;

        // setup our left pointer
        int left = 0;
        // setup our right pointer
        int right = numbers.size() - 1;

        // loop as long as the pointers don't overlap
        while (left < right) {
            // get the sum of the array values pointed to by the left and right pointers
            int sum = numbers[left] + numbers[right];

            // if the sum equals the target, then we found our indices
            // add the 1-indexed indices to the results vector
            // and break out of the while loop
            if (sum == target) {
                result.push_back(left+1);
                result.push_back(right+1);
                break;
            }
            // else check if our sum too small
            // if it is, we increment the left pointer
            // because it points to the smaller number
            else if (sum < target) {
                ++left;
            }
            // else our sum is too large
            // so we increment the right pointer
            // because it points to the larger number
            else {
                --right;
            }
        }

        // finally, we return the results vector
        return result;
    }
};
