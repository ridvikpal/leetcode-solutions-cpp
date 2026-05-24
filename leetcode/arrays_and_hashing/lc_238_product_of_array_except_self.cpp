#include <vector>

/**
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * Time complexity: O(n) where n = length of nums
 * Space complexity: O(n) where n = length of nums
 */
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        // create our results array
        // with the same size as nums
        // and prepopulated with all 1s
        std::vector<int> result(nums.size(), 1);

        // we will first perform a prefix product
        // so init our running product to the first number
        int runningProduct{nums[0]};
        // loop from 1 -> the last index in nums
        // aka. loop in forward order skipping first number
        for (int i{1}; i < nums.size(); ++i) {
            // set the current result value to the
            // product of the numbers before it
            result[i] = runningProduct;
            // update the running product by multiplying
            // by the current number
            runningProduct *= nums[i];
        }

        // now we will do a postfix product
        // so init our running product to the last number
        runningProduct = nums[nums.size()-1];
        // loop from the second last index -> 0 in nums
        // aka. loop in reverse order skipping last number
        for (int i{static_cast<int>(nums.size())-2}; i >= 0; --i) {
            // multiply the current result value
            // with the product of the numbers after it
            result[i] *= runningProduct;
            // update the running product by multiplying
            // by the current number
            runningProduct *= nums[i];
        }

        // finally return the result array
        return result;
    }
};
