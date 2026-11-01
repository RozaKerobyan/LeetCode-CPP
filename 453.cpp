class Solution {
public:
    int minMoves(vector<int>& nums)
    {
        int minNum = nums[0];
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (nums[i] < minNum)
                minNum = nums[i];
        }
        return sum - minNum * nums.size();
    }
};