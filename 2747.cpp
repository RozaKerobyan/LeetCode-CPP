class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) 
    {
        vector<pair<int, int>> sortedQueries;
        vector<int> ans(queries.size(), 0);
        unordered_map<int, int> freq;

        for (int i = 0; i < queries.size(); i++)
            sortedQueries.push_back({queries[i], i});
        sort(logs.begin(), logs.end(), [](const vector<int> &a, const vector<int> &b)
        {
            return a[1] < b[1];
        });
        sort(sortedQueries.begin(), sortedQueries.end());

        int left = 0;
        int right = 0;
        int activeServers = 0;

        for (size_t i = 0; i < sortedQueries.size(); i++)
        {
            auto &q = sortedQueries[i];
            
            int start = q.first - x;
            int end = q.first;
            int idx = q.second;

            while (right < logs.size() && logs[right][1] <= end)
            {
                int id = logs[right][0];
                if (freq[id] == 0)
                    activeServers++;
                freq[id]++;
                right++;
            }
            while (left < right && logs[left][1] < start)
            {
                int id = logs[left][0];

                freq[id]--;
                if (freq[id] == 0)
                    activeServers--;
                left++;
            }
            ans[idx] = n - activeServers;
        }
        return (ans);
    }
};
