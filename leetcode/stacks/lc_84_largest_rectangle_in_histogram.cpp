#include <vector>
#include <stack>

/**
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * Time complexity: O(n) where n = length of heights
 * Space complexity: O(n) where n = length of heights
 */
class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        // we will use a monotonically increasing stack based on height
        // where we store the start index (for computing width)
        // and the corresponding height
        std::stack<std::pair<int, int>> heightStack;

        // init our max area and start index (for computing width)
        int maxArea = 0;
        int startIndex = 0;

        // loop through all the heights
        for (int i = 0; i < heights.size(); ++i) {
            // init the starting index to be this current index
            // on each iteration of the loop
            startIndex = i;

            // standard monotonic stack while loop, but we compare the height (second element in pair)
            while (!heightStack.empty() && heights[i] < heightStack.top().second) {
                // since we have encountered a smaller height, now we can update
                // our start index to be the index of the larger height we will pop
                startIndex = heightStack.top().first;
                // compute the width of the rectangle
                int width = i - startIndex;
                // compute the area of the rectangle
                int area = width * heightStack.top().second;

                // update the max area
                maxArea = std::max(area, maxArea);

                // pop the larger height element from the stack
                heightStack.pop();
            }

            // we only add to the height stack if it is empty
            // or if we have a new, unique height to add
            if (heightStack.empty() || heightStack.top().second != heights[i]) {
                heightStack.push(std::make_pair(startIndex, heights[i]));
            }
        }

        // it's possible after looping through all heights, we still have
        // elements in the stack (e.g., if we had a fully increasing section in array)
        // so we will check all the elements in the stack, and compute their area
        // just like in the monotonic while loop above
        while (!heightStack.empty()) {
            // compute the width
            int width = heights.size() - heightStack.top().first;
            // compute the area
            int area = width * heightStack.top().second;

            // update the max area accordingly
            maxArea = std::max(area, maxArea);

            // pop the element from the stack
            heightStack.pop();
        }

        // finally, we will return the max area
        return maxArea;
    }
};
