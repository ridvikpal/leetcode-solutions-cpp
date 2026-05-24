#include <string>
#include <unordered_map>

/**
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * Time complexity: O(n) where n = longest string length between s and t
 * Space complexity: O(1) because there can only be 26 letters used
 */
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        // create our hashamp to store the count of
        // each char in string s
        std::unordered_map<char, int> s_counter;
        // create our hashamp to store the count of
        // each char in string t
        std::unordered_map<char, int> t_counter;

        // loop through all chars in string s
        for (const char& s_char : s) {
            // increment the count of this char
            // in our s_counter hashmap
            s_counter[s_char] += 1;
        }

        // loop through all chars in string t
        for (const char& t_char : t) {
            // increment the count of this char
            // in our t_coutner hashmap
            t_counter[t_char] += 1;
        }

        if (s_counter == t_counter) {
            // if the two counters contain the same values
            // they are anagrams so return true
            return true;
        }

        // else we can return because they are not anagrams
        return false;
    }
};
