#include <vector>
#include <algorithm>

/**
 * https://leetcode.com/problems/koko-eating-bananas/description/
 *
 * Time complexity: O(log(m) * n) where m = max element in piles and n = length of piles
 * Space complexity: O(1)
 */
class Solution {
public:
    // create a helper function to compute the total time
    // it takes to eat the piles with a speed of k
    long long computeTimeToEat(const std::vector<int>& piles, const int& k) {
        // init our total time
        // we use long long because we need a 64 bit int
        long long totalTime = 0;

        // loop through all piles
        for (const int& pile: piles) {
            // init our time
            // also a long long because we need it to be 64 bits
            long long time = 0;

            // compute the remainder of the time first
            int timeRemainder = pile % k;

            // if the remainder is 0, then we have perfect integer division
            // so we can directly compute the time
            if (timeRemainder == 0) {
                time = pile / k;
            // else if the remainder is not 0, we need to add 1 to the time to round up
            } else {
                time = (pile / k) + 1;
            }

            // on each iteration, increment the total time
            totalTime += time;

        }

        // finally, return the total time
        return totalTime;
    }

    int minEatingSpeed(std::vector<int>& piles, int h) {
        // the max k speed is always going to be the max pile, so find it
        int maxK = *std::max_element(piles.begin(), piles.end());

        // then we will do a binary search from the range [1, 2, ..., maxK]
        // to find the optimal k value
        // init our left value is 1
        int left = 1;
        // init our right value to be maxK
        int right = maxK;

        // init our bestK to be maxK+1
        int bestK = maxK+1;

        // standard binary search while loop
        while (left <= right) {
            // compute the middle k value;
            int middleK = (left + right) / 2;

            // get the time it takes to eat the piles with this middle k value
            long long time = computeTimeToEat(piles, middleK);

            // if the time is less than or equal to h, we have a valid k speed
            if (time <= h) {
                // so update our best k value accordingly
                bestK = std::min(middleK, bestK);
                // and update our right pointer so we search for an even smaller k
                right = middleK - 1;
            // else the time is greater than k, so we don't have a valid k speed
            } else {
                // update the left pointer so we search for a larger k
                left = middleK + 1;
            }
        }

        // finally, return the best k value
        return bestK;
    }
};
