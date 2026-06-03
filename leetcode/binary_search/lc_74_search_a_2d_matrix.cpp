#include <vector>

/**
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * Time complexity: O(log(n) + log(m)) where n = number of rows and m = number of columns in the matrix
 * Space complexity: O(1)
 */
class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        // first get the dimensions of matrix
        int rowLen = matrix.size();
        int colLen = matrix[0].size();

        // setup our top, bottom and middleRow pointers
        // since we will do binary search to find the right middle row
        int top = 0, bottom = rowLen-1, middleRow = 0;

        // standard binary search loop
        while (top <= bottom) {
            // compute the middle row
            middleRow = (top + bottom) / 2;

            // if we have found our target in the row, then break immediately since we found the right row
            if (matrix[middleRow][0] <= target && target <= matrix[middleRow][colLen-1]) {
                break;
            // else if the target is larger than the last element in the middle row, update the top pointer
            } else if (target > matrix[middleRow][colLen-1]) {
                top = middleRow + 1;
            // or finally if the target is smaller than the first element in the middle row, update the bottom pointer
            } else if (target < matrix[middleRow][0]) {
                bottom = middleRow - 1;
            }
        }

        // setup our left and right pointers for a standard binary search
        // to find the right column
        int left = 0, right = colLen-1;

        // standard binayr search loop
        while (left <= right) {
            // compute the middle column
            int middleCol = (left + right) / 2;

            // if we have found our target, we can directly return true
            if (matrix[middleRow][middleCol] == target) {
                return true;
            }

            // else check if the target is greater than the element
            // where we have to update the left pointer
            if (target > matrix[middleRow][middleCol]) {
                left = middleCol + 1;
            // else the target is smaller than the element
            // where we have to update the right pointer
            } else if (target < matrix[middleRow][middleCol]) {
                right = middleCol - 1;
            }
        }

        // finally, after checking the entire matrix if we don't find the element
        // then return false
        return false;
    }
};
