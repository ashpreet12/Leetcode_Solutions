class Solution {
public:
    void dfs(vector<vector<int>>&adjList,int source,vector<bool>&visited){
        visited[source] = true;
        for(auto x : adjList[source]){
            if(visited[x] == false){
                dfs(adjList,x,visited);
            }
        }
    }
    vector<vector<int>>getAdjList(vector<vector<int>>&adjMat,int n){
        vector<vector<int>>adjList(n);
        for(int row = 0; row < adjMat.size();row++){
            for(int col = 0;col < adjMat[row].size();col++){
                if(adjMat[row][col] == 1 && row != col){
                    adjList[row].push_back(col);
                }
            }
        }
        return adjList;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adjList = getAdjList(isConnected,n);
        vector<bool>visited(n,false);

        int provinces = 0;

        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                dfs(adjList,i,visited);
                provinces++;
            }
        }
        return provinces;
    }
};