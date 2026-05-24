#include <vector>
#include <unordered_set>

/**
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * Time complexity: O(n) where n = length of nums
 * Space complexity: O(n) where n = length of nums
 */
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        // create our hashset to store numbers we have seen before
        std::unordered_set<int> seen;

        // loop through all numbers
        for (const int& num : nums) {
            if (seen.find(num) != seen.end()) {
                // if we have seen this number before
                // return true
                return true;
            }
            
            // add each number to our seen hashset
            seen.insert(num);
        }

        // if we get through all numbers and don't find
        // a duplicate we can return false
        return false;
    }
};
