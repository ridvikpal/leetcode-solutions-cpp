#include <vector>

/**
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * Time complexity: O(n) where n = length of price
 * Space complexity: O(1)
 */
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // if the length of the prices array is less than 2
        // then we cannot buy and sell, so return 0 immediately
        if (prices.size() < 2) {
            return 0;
        }

        // init the minimum price
        int minPrice = prices[0];
        // init the maxProfit we can get
        int maxProfit = 0;

        // loop through all prices after the first one
        for (int i = 1; i < prices.size(); ++i) {
            // if the current price is less than the min price
            // then update the minPrice
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }

            // update the max profit as the difference
            // between the min price and current price
            maxProfit = std::max(maxProfit, prices[i]-minPrice);
        }

        // finally, return the maximum profit
        return maxProfit;
    }
};
