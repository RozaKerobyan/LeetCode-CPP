class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > available;

        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>> > busy;

        vector<int> ans(tasks.size());
        for (int i = 0; i < servers.size(); i++)
            available.push({servers[i], i});
        long long time = 0;
        for (int i = 0; i < tasks.size(); i++)
        {
            time = max(time, (long long)i);
            while (!busy.empty() && get<0>(busy.top()) <= time)
            {
                int finish = get<0>(busy.top());
                int weight = get<1>(busy.top());
                int id = get<2>(busy.top());

                busy.pop();
                available.push({weight, id});
            }
            if (available.empty())
                time = get<0>(busy.top());
            while (!busy.empty() && get<0>(busy.top()) <= time)
            {
                int finish = get<0>(busy.top());
                int weight = get<1>(busy.top());
                int id = get<2>(busy.top());

                busy.pop();
                available.push({weight, id});
            }
            int weight = available.top().first;
            int id = available.top().second;

            available.pop();
            ans[i] = id;
            busy.push({time + tasks[i], weight, id});
        }
        return (ans);
    }
};
