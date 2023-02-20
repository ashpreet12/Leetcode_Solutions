class Solution {
public:
    bool isValid(int row,int col,int n){
        return row >= 0 && col >= 0 && row < n && col < n;
    }
    vector<pair<int,int>>getAdjacencyList(pair<int,int>p,int n){
        vector<pair<int,int>>adjList;
        int row = p.first;
        int col = p.second;
        if(isValid(row + 1,col,n)){
            adjList.push_back({row + 1,col});
        }
        if(isValid(row - 1,col,n)){
            adjList.push_back({row - 1,col});
        }
        if(isValid(row ,col + 1,n)){
            adjList.push_back({row,col + 1});
        }
        if(isValid(row,col - 1,n)){
            adjList.push_back({row,col - 1});
        }
        if(isValid(row + 1,col + 1,n)){
            adjList.push_back({row + 1,col + 1});
        }
        if(isValid(row - 1,col - 1,n)){
            adjList.push_back({row - 1,col - 1});
        }
        if(isValid(row + 1,col - 1,n)){
            adjList.push_back({row + 1,col - 1});
        }
        if(isValid(row - 1,col + 1,n)){
            adjList.push_back({row - 1,col + 1});
        }
        return adjList;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>>visited(n,vector<bool>(n ,false));
        queue<pair<int,int>>q;
        if(grid[0][0] == 0){
            q.push({0,0});
            visited[0][0] = true;
        }
        
        int shortestPath = 0;
        while(!q.empty()){
            int nodesPushed = q.size();
            shortestPath++;

            for(int cnt = 0;cnt < nodesPushed;cnt++){
                pair<int,int>top = q.front();
                cout<<top.first<<top.second<<" ";
                q.pop();
           
                if(top.first == n-1 and top.second == n-1) return shortestPath;
                for(auto x : getAdjacencyList(top,n)){
                    if(visited[x.first][x.second] == false && grid[x.first][x.second] == 0){
                        q.push({x.first,x.second});
                        visited[x.first][x.second] = true;
                    }
                }
            } 
        }
        return -1;
    }
};