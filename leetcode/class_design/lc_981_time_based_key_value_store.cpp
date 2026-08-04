#include <unordered_map>
#include <vector>
#include <string>

/**
 * https://leetcode.com/problems/time-based-key-value-store/description/
 *
 * Time complexity: O(1) for set()
 *                  O(log(n)) where n = largest number of (value, timestamp) pairs for a given key for get()
 * Space complexity: O(n) where n = total number of (key, value, timestamp) triples
 */
class TimeMap {
public:
    // we will use a hashmap where the value is an array of pairs
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> timeMap;

    TimeMap() {

    }

    void set(std::string key, std::string value, int timestamp) {
        // simply add the timestamp, value pair to the corresponding key
        timeMap[key].push_back(std::make_pair(timestamp, value));
    }

    std::string get(std::string key, int timestamp) {
        // first attempt to find the vector corresponding to the key
        const auto valuesIterator = timeMap.find(key);

        // if the key is not found, then return an empty string
        if (valuesIterator == timeMap.end()) {
            return "";
        }

        // otherwise, get the vector corresponding to the key
        const std::vector<std::pair<int, std::string>>& values = valuesIterator->second;

        // we will perform binary search to efficiently find the key associated with the optimal timestamp
        // we can do this because we know values will always be ordered by increasing timestamps
        // init the left and right pointers, as well as the result string
        int left = 0;
        int right = values.size()-1;
        std::string result = "";

        // standard binary search while loop until left/right pointers overlap
        while (left <= right) {
            // get the middle pivot
            int middle = (left+right) / 2;

            // get the time and value associated with the middle pivot
            const auto& [time, val] = values[middle];

            // if the time equals the timestamp, immediately return the value
            if (time == timestamp) {
                return val;
            }

            // otherwise, if the time < timestamp, update the result
            // and search for a greater time by updating the left pointer
            if (timestamp > time) {
                result = val;
                left = middle+1;
            // else time > timestamp and search for a smaller time by updating
            // the right pointer
            } else {
                right = middle-1;
            }
        }

        // finally, return the result
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
