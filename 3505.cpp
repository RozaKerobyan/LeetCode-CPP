class MedianCost {
private:
    multiset<int> left;
    multiset<int> right;
    long long sumLeft = 0;
    long long sumRight = 0;

    void balance() {
        while (left.size() > right.size() + 1) 
        {
            int val = *left.rbegin();
            left.erase(prev(left.end()));
            sumLeft -= val;

            right.insert(val);
            sumRight += val;
        }

        while (right.size() > left.size())
        {
            int val = *right.begin();
            right.erase(right.begin());
            sumRight -= val;

            left.insert(val);
            sumLeft += val;
        }
    }

public:
    void add(int val) 
    {
        right.insert(val);
        sumRight += val;

        int mid = *right.begin();
        right.erase(right.begin());
        sumRight -= mid;

        left.insert(mid);
        sumLeft += mid;

        balance();
    }

    void remove(int val) {
        auto it = left.find(val);

        if (it != left.end()) 
        {
            left.erase(it);
            sumLeft -= val;
        }
        else
        {
            it = right.find(val);
            right.erase(it);
            sumRight -= val;
        }

        balance();
    }

    long long getCost() 
    {
        long long median = *left.rbegin();

        long long leftCost = median * left.size() - sumLeft;
        long long rightCost = sumRight - median * right.size();

        return leftCost + rightCost;
    }
};

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        dp[0][0] = 0;

        MedianCost window;

        for (int i = 1; i <= n; i++) 
        {
            window.add(nums[i - 1]);
            for (int j = 0; j <= k; j++) 
            {
                dp[i][j] = dp[i - 1][j];

                if (j > 0 && i >= x)
                {
                    long long cost = window.getCost();

                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost
                    );
                }
            }
            if (i >= x)
                window.remove(nums[i - x]);
        }
        return dp[n][k];
    }
};
