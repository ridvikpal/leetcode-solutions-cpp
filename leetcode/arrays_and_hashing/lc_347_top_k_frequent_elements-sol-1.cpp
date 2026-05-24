#include <vector>
#include <unordered_map>
#include <algorithm>

/**
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * Time complexity: O(n * k * u) where n = length of nums, u = number of unique nums in nums
 * Space complexity O(u) where u = number of unique nums in nums
 */
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // create a hashmap to count the frequency of each number
        std::unordered_map<int, int> counter;
        // create our results array
        std::vector<int> result;

        // loop through all numbers
        for (const int& num : nums) {
            // increment the count of each number
            counter[num] += 1;
        }

        // loop from 0 to k-1
        for (int i{0}; i < k; ++i) {
            // get the element with the max count in the counter hashmap
            auto iterator = std::max_element(counter.begin(), counter.end(),
                [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                    return a.second < b.second;
                });

            // add the number to the results array
            result.push_back(iterator->first);
            // remove the number we just added from the hashmap
            counter.erase(iterator->first);
        }

        // finally, return the results array
        return result;
    }
};
