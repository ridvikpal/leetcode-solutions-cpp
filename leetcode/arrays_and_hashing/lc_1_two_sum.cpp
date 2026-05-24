#include <vector>
#include <unordered_map>

/**
 * https://leetcode.com/problems/two-sum/description/
 *
 * Time complexity: O(n) where n = length of nums
 * Space complexity: O(n) where n = length of nums
 */
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // create our final result array
        std::vector<int> result;
        // create our seen hashmap to store the numbers we've
        // seen at their indexes.
        std::unordered_map<int, int> seen;

        // loop through all numbers
        for (int i{0}; i < nums.size(); ++i) {
            // get the difference between the target
            // and the current number
            int difference = target - nums[i];
            // check if we have seen this difference before
            // aka. if difference is stored in our hashmap.
            auto iterator = seen.find(difference);

            if (iterator != seen.end()) {
                // if we have seen this difference before
                // then add the index of the difference to our result
                // along with the current number's index
                // since current number + difference = target
                result.push_back(iterator->second);
                result.push_back(i);

                // finally return the result
                return result;
            }

            // if we have not seen the difference
            // then add the difference to our seen hashmap
            seen[nums[i]] = i;
        }

        // if no solution is found, return an empty array
        return result;
    }
};
