class Solution {
public:
    bool isValid(int row,int col,int m,int n){
        return row >= 0 && col >= 0 && row < m && col < n;
    }
    bool isEntrance(int row,int col,vector<int>& entrance){
        return row == entrance[0] && col == entrance[1];
    }
    bool isBoundary(int row,int col,int m,int n,vector<int>& entrance){
        return (row == 0 || col == 0 || row == m - 1 || col == n - 1) && (!isEntrance(row,col,entrance)); 
    }
    vector<pair<int,int>>getAdjacencyList(pair<int,int>p,int m,int n){
        vector<pair<int,int>>adjList;
        int row = p.first;
        int col = p.second;
        if(isValid(row + 1,col,m,n)){
            adjList.push_back({row + 1,col});
        }
        if(isValid(row - 1,col,m,n)){
            adjList.push_back({row - 1,col});
        }
        if(isValid(row ,col + 1,m,n)){
            adjList.push_back({row,col + 1});
        }
        if(isValid(row,col - 1,m,n)){
            adjList.push_back({row,col - 1});
        }
        return adjList;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n ,false));
        queue<pair<int,int>>q;
        
        q.push({entrance[0],entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        
        int shortestPath = -1;
        while(!q.empty()){
            int nodesPushed = q.size();
            shortestPath++;

            for(int cnt = 0;cnt < nodesPushed;cnt++){
                pair<int,int>top = q.front();
                q.pop();
           
            if(isBoundary(top.first,top.second,m,n,entrance) && maze[top.first][top.second] == '.'){
                    return shortestPath;
            }
                for(auto x : getAdjacencyList(top,m,n)){
                    if(visited[x.first][x.second] == false && maze[x.first][x.second] == '.'){
                        q.push({x.first,x.second});
                        visited[x.first][x.second] = true;
                    }
                }
            } 
        }
        return -1;
    }
};