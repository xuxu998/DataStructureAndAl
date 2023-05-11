// Queue
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> D(n + 1,INT_MAX);
        auto com =[](const pair<int,int>& a, const pair<int,int>& b){
            return a.second > b.second;};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(com)> q(com);
        int res = 0;
        D[k] = 0;
        q.push({k,0});
        while(!q.empty())
        {
            int min_dis_vertex = q.top().first;
            q.pop();
            for(int i = 0 ; i < times.size() ; i++)
            {
                if(times[i][0] == min_dis_vertex and D[times[i][1]] > D[times[i][0]] + times[i][2])
                {
                    D[times[i][1]] = D[times[i][0]] + times[i][2];
                    q.push({times[i][1],D[times[i][1]]});
                }
            }
        }
        for(int i = 1 ; i <= n ; i++)
            if(D[i] != INT_MAX)
                res = max(res,D[i]);
            else
                return -1;
        return res;
    }
};
// Non-queue
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> D(n + 1,INT_MAX);
        vector<bool> included(n + 1,false);
        int res = 0;
        D[k] = 0;
        for(int i = 1; i <= n ; i++)
        {
            int min_dis_vertex = 0;
            int min_ = INT_MAX;
            for(int j = 1; j <= n; j++)
                if(D[j] < min_ and included[j] == false)
                    min_dis_vertex = j, min_ = D[j];
            included[min_dis_vertex] = true;
            for(int i = 0 ; i < times.size() ; i++)
            {
                if(times[i][0] == min_dis_vertex and included[times[i][1]] == false and D[times[i][1]] > D[times[i][0]] + times[i][2])
                    D[times[i][1]] = D[times[i][0]] + times[i][2];
            }
        }
        for(int i = 1 ; i <= n ; i++)
            if(D[i] != INT_MAX)
                res = max(res,D[i]);
            else
                return -1;
        return res;
    }
};
