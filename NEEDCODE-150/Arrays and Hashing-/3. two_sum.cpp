    class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mapname;

        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            if (mapname.find(t) != mapname.end())
                return {mapname[t], i};
            else
                mapname[nums[i]] = i;
        }
    }}
    ;