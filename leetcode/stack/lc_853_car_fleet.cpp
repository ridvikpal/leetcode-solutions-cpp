#include <vector>
#include <stack>
#include <algorithm>

/**
 * https://leetcode.com/problems/car-fleet/description/
 *
 * Time complexity: O(n) where n = length of position/speed array
 * Space complexity: O(n) where n = length of position/speed array
 */
class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        // first we will create an array that combines
        // the positions and times of each char
        // and populate it
        std::vector<std::pair<int, int>> positionsAndTimes;
        for (int i = 0; i < position.size(); ++i) {
            positionsAndTimes.push_back(std::make_pair(position[i], speed[i]));
        }

        // we will sort the positions and times in descending lexicographic order
        // because we want to analyze the cars that are closest to the target first
        std::sort(positionsAndTimes.begin(), positionsAndTimes.end(), std::greater<>());

        // create a stack that will contain the times for each car fleet
        // note this is a float because we can have decimal times
        std::stack<float> carFleetTimes;

        // loop through the positions and times array
        for (int i = 0; i < positionsAndTimes.size(); ++i) {
            // get the position and velocity
            const auto& [pos, vel] = positionsAndTimes[i];

            // compute the arrival time to the destination as a float
            // to get float from an int, we must static cast one of the ints
            // before we divide
            float time = static_cast<float>(target-pos) / vel;

            // a new car fleet only gets formed if each car, as it arrives to the destination,
            // arrives after the previous car
            // aka. only if the current car's arrival time is later than the last fleet's
            // arrival time
            if (carFleetTimes.empty() || time > carFleetTimes.top()) {
                carFleetTimes.push(time);
            }
        }

        // return the size of the car fleet times stack to get the num of car fleets
        return carFleetTimes.size();
    }
};
