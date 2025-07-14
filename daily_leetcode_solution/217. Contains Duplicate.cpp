class Solution {
private:
    unordered_map<int, bool> num_logger;
    bool isDuplicateNum(int num){
        return num_logger[num] == true;
    }
public:
    bool containsDuplicate(vector<int>& nums) {
        num_logger.clear();
        for(auto num : nums)
        {
            if(isDuplicateNum(num)) return true;
            num_logger[num] = true;
        }

        return false;
        // time: O(n) space: O(n)
    }
};