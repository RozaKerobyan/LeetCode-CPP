class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2)
    {
        long long m = min(need1, need2);

        long long a = m * min(costBoth, cost1 + cost2);
        long long b = (need1 - m) * min(cost1, costBoth);
        long long c = (need2 - m) * min(cost2, costBoth);

        return (a + b + c);    
    }
};
