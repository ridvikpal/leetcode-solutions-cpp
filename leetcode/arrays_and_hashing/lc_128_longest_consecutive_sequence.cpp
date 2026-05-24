#include <vector>
#include <unordered_set>

/**
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * Time complexity: O(n) where n = length of nums
 * Space complexity: O(n) where n = length of nums
 */
class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        // first begin by creating a unique nums set from the nums vector
        // to remove all duplicates
        std::unordered_set<int> uniqueNums(nums.begin(), nums.end());

        // then init our max count for the longest consecutive subsequence
        int maxCount = 0;

        // loop through all unique numbers
        for (int num: uniqueNums) {
            // if the previous consecutive number is
            // not found in our unique nums set
            // we can begin looking for a consecutive sequence
            // that is larger than this number
            // this ensures we only visit each unique number once
            if (!uniqueNums.contains(num-1)) {
                // init our temporary count to 1
                int count = 1;

                // loop through our unique nums
                // searching for a larger consecutive number
                // each time, incrementing count accordingly
                while (uniqueNums.contains(num+1)) {
                    count += 1;
                    num += 1;
                }

                // update the max count once we cannot find a
                // larger consecutive number
                maxCount = std::max(maxCount, count);
            }
        }

        // finally return the max count we found
        return maxCount;
    }
};
