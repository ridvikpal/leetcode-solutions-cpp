#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>

/**
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * Time complexity: O(n * k) where n = length of strs, k = longest string length in strs
 * Space complexity: O(n * k) where n = length of strs, k = longest string length in strs
 */
class Solution {
public:
    // create a helper function to count the number of chars
    // in a given string
    std::array<int, 26> countChars(const std::string& str) {
        // init our array to count the number of chars in the string
        // index = char (0 = a, 1 = b, ...)
        // value = count of the char
        std::array<int, 26> counter{};

        // loop through all chars in the string
        for (const char& chr: str) {
            // increment the counter array value
            counter[static_cast<int>(chr) - static_cast<int>('a')] += 1;
        }

        // return the counter array
        return counter;
    }

    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // init our 2d results array where each element is an array of anagram strings
        std::vector<std::vector<std::string>> result;
        // init our hashmap where
        // key = stringified counter array values from countChars() separated by #
        // value = array of strings with the same counter array (anagrams)
        std::unordered_map<std::string, std::vector<std::string>> anagramMap;

        // loop through all strings
        for (const std::string& str: strs) {
            // get this string's counter array using the helper function
            std::array<int, 26> counter = countChars(str);

            // init the string's key for the angaramMap
            std::string key = "";

            // loop through each counter value
            for (const int& count : counter) {
                // append it to the string separated by a #
                key += std::to_string(count) + '#';
            }

            // append string to the correct array in the anagramMap
            // using the string's key
            anagramMap[key].push_back(str);
        }

        // loop through all elements in the anagramMap
        // append each array of anagram strings to the results array
        for (const auto& anagramMapPair : anagramMap) {
            result.push_back(anagramMapPair.second);
        }

        // finally, return the results array
        return result;
    }
};
