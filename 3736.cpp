class Solution {
public:
    int minMoves(vector<int>& nums) 
    {
        int maxNum = std::ranges::max(nums);
        int moves = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            moves += maxNum - nums[i];
        }
        return (moves);
    }
};
