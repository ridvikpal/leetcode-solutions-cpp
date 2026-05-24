#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

/**
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * Time complexity: O(n * klog(k)) where n = length of strs, k = longest string length in strs
 * Space complexity O(n * k) where n = length of strs, k = longest string length in strs
 */
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // init our result 2d array, where each element will be
        // an array containing anagrams
        std::vector<std::vector<std::string>> result;
        // init our anagram map which maps sorted strings
        // to array of strings which are anagrams of the sorted strings
        std::unordered_map<std::string, std::vector<std::string>> anagramMap;

        // loop through all given strings
        for (const std::string& str: strs) {
            // copy the current string into a new string str_key
            // this will be the key for the anagram map
            std::string str_key = str;
            // sort the str_key
            std::sort(str_key.begin(), str_key.end());

            // add the current string to the anagram map
            // with the str_key as the key
            anagramMap[str_key].push_back(str);
        }

        // loop through all key, value pairs in the anagram map
        for (const auto& anagramMapPair : anagramMap) {
            // add each array of anagrams to the results array
            result.push_back(anagramMapPair.second);
        }

        // finally return the result array
        return result;
    }
};
