#include <string>
#include <algorithm>

/**
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * Time complexity: O(n) where n = length of s
 * Space complexity: O(1)
 */
class Solution {
public:
    bool isPalindrome(std::string s) {
        // we will use a two pointer approach
        // init our left pointer to point to the first char
        int l{0};
        // init our right pointer to point to the last char
        int r{static_cast<int>(s.size())-1};

        // standard two pointer loop
        // for as long as the left pointer
        // does not overlap the right pointer
        while (l <= r) {
            while (!std::isalnum(s[l])) {
                // as long as the left char is not alphanumeric
                // increment the left pointer to the next left char
                ++l;
                // if the left pointer overlaps the right pointer
                // then return true because no more chars to check
                // this is a palindrome
                if (l > r) {
                    return true;
                }
            }

            while (!std::isalnum(s[r])) {
                // as long as the right char is not alphanumeric
                // decrement the pointer to the next right char
                --r;
                // if the left pointer overlaps the right pointer
                // then return true because no more chars to check
                // this is a palindrome
                if (l > r) {
                    return true;
                }
            }

            // otherwise, if the left and right chars are not the same
            // return false becaues it's not a palindrome
            if (std::tolower(s[l]) != std::tolower(s[r])) {
                return false;
            }

            // move to the next left pointer
            ++l;
            // move to the next right pointer
            --r;
        }

        // after checking each char and no violation found
        // return true because the string is a palindrome
        return true;
    }
};
