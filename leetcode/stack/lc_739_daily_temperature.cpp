#include <vector>
#include <stack>

/**
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * Time complexity: O(n) where n = length of temperatures
 * Space complexity: O(n) where n = length of temperatures
 */
class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        // init our result vector with all 0s
        std::vector<int> result(temperatures.size());
        // init our monotonic decreasing stack
        // note our stack will contains indices, not actual temperature values
        std::stack<int> tempIndexStack;

        // loop through all the temperature indices
        for (int i = 0; i < temperatures.size(); ++i) {
            // standard while loop to maintain monotonic decreasing property
            while (!tempIndexStack.empty() && temperatures[i] > temperatures[tempIndexStack.top()]) {
                // the number of days until we find a larger temperature
                // for any index in the stack is equal to i - that index in the stack
                // now that we found a larger temperature, then update our results array accordingly
                result[tempIndexStack.top()] = i - tempIndexStack.top();

                // in order to maintain our monotonic decreasing property, we will
                // remove all indices from our stack whose temperatures are smaller
                // than the current temperature
                tempIndexStack.pop();
            }

            // finally, we always add the current temperature index to the stack
            tempIndexStack.push(i);
        }

        // finally, return the result array
        return result;
    }
};
