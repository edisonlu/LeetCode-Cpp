class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> tMap;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto it = tMap.find(target -nums[i]);
            if(it != tMap.end())
                return vector<int>{i, it->second};
            tMap[nums[i]] = i;
        }
        return vector<int>();
    }
};
