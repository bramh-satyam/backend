class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // logs the remainder after subtracting the key from the target
        unordered_map<int, int> remainder_logger;

        int index  = 0;
        for(auto num: nums)
        {
            if(remainder_logger.find(num) == remainder_logger.end())
            {
                remainder_logger[target - num] = index;
            }
            else
            {
                return {remainder_logger[num], index};
            }
            index++;
        }

        // default
        return {-1, -1};
    }
};


/*
Follow Ups and learning

1. What if `nums` had duplicate numbers in it?

    well that is taken care, let's say nums = [3, 3] and target = 6
    then first iteration remainder_logger = {3 : 0} -> target - num = 6 - 3 = 3 and index = 0
    then second interation remainder_logger.find(3) doesn't return .end() thus its found
    so it would return {remainder_logger[num], index} = {remainder_logger[3], 1} = {0: 1}

    So, basically duplicates are handled here


2. What if the `nums` had negative numbers in it?

    well that is taken care again, let's say nums = [-1, 2, 9] and target = 8
    then first iteration it won't find anything in the remainder_logger since there is no data
    remainder_logger = {9 : 0} -> target - num = 8 - (-1) = 9 and index = 0
    then second iteration, remainder_logger.find(2) -> remainder_logger.end(), thus remainder_logger = {9 : 0, 6 : 1}
    then third iteration, remainder_logger.find(9) doesn't give .end() thus it would return {remainder_logger[num], index}
    which is {remainder_logger[9], 2} = {0, 2}

** Learning **

if I would have written "if (map[num])" and the case was like target  = 6 and nums = [3,3] then after first iteration it fails since the index is 0, because map[3] == 0, and if (0) is false. Thus it's is asked not to use this, instead 
use "if (map.find(complement) != map.end())" , this takes care of this bug!
*/