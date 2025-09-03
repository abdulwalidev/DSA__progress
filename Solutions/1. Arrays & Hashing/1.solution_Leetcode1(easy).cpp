#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // Map to store value -> index

        // Loop through the array
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i]; // Find the number we need to reach the target

            // Check if that number is already in the map
            if (mp.find(complement) != mp.end()) {
                // If found, return its index and the current index
                return {mp[complement], i};
            }

            // Otherwise, store the current number and its index in the map
            mp[nums[i]] = i;
        }

        // If no pair is found (should not happen as per problem statement)
        return {};
    }
};
