class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n -1)
        {
            return -1;
        }
        vector<vector<int>> map_(n);
        vector<int> mark(n,0);
        queue<int> q;
        int count_ = 0;
        for(int i = 0;i < connections.size(); i++)
        {
            map_[connections[i][0]].push_back(connections[i][1]);
            map_[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(mark[i] == 0)
            {
                q.push(i);
                mark[i] = 1;
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for(auto element: map_[node])
                    {
                        if(mark[element] == 0)
                        {
                            q.push(element);
                            mark[element] = 1;
                        }
                    }
                }
                count_++;
            }
        }
        return count_-1;
    }
};