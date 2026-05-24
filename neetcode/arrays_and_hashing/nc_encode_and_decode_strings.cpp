#include <string>
#include <vector>

/**
 * https://neetcode.io/problems/string-encode-and-decode/question
 *
 * Time complexity: O(n) where n is length of strs
 * Space complexity: O(n) where n is length of strs
 */
class Solution {
public:

    // define the special character used to separate strings
    const char SPECIAL_CHAR = '#';

    std::string encode(std::vector<std::string>& strs) {
        // init our result string
        std::string result;

        // loop through all strings
        for (const std::string& str : strs) {
            // append to result string:
            // 1) the length of the string
            // 2) the special char
            // 3) the string itself
            result += std::to_string(str.size()) + SPECIAL_CHAR + str;
        }

        // finally return the result string
        return result;
    }

    std::vector<std::string> decode(std::string s) {
        // init the results array
        std::vector<std::string> result;

        // loop until we have gone through the entire string
        int i = 0;
        while (i < s.size()) {
            // loop our second j pointer until we reach the special char
            int j = i;
            while (s[j] != SPECIAL_CHAR) {
                ++j;
            }

            // once we reach the special char
            // we know that chars at indices from i->j-1
            // contain the length of each string
            // so store that in numChars
            const int numChars = std::stoi(s.substr(i, j-i));
            // remember special char is at index j now
            // so set i to be the first char after the special char
            // which is the first char of the actual string
            i = j+1;

            // the actual string now begins at index i
            // and continues for numChars
            // including first char at index i as part of the count
            result.push_back(s.substr(i, numChars));
            // increment the i pointer forward numChars now
            // this will set i to point to the first number
            // of the length of the next string
            i += numChars;
        }

        // finally we can return the result array
        return result;
    }
};
