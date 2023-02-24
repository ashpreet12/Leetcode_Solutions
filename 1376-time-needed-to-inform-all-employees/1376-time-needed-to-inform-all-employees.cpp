class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> v[n];
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            v[manager[i]].push_back(i);
        }
        queue<pair<int, int>> q;
        q.push({headID, 0});
        int ans=0;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                auto p=q.front();
                ans=max(ans, p.second);
                q.pop();
                for(int j=0;j<v[p.first].size();j++)
                q.push({v[p.first][j], p.second+informTime[p.first]});
            }
        }
        return ans;
    }
};