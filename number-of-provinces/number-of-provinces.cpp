class Solution {
public:
    void dfsRec(vector<vector<int>> &adjList,int source,vector<bool>&visited){
        visited[source] = true;
        
        for(auto x : adjList[source]){
            if(visited[x] == false){
                dfsRec(adjList,x,visited);
            }
        }
    }
    int countComponents(vector<vector<int>> &adjList){
        int components = 0;
        vector<bool> visited(adjList.size(),false);
        for(int i = 1; i < adjList.size();i++){
            if(visited[i] == false){
                components++;
                dfsRec(adjList,i,visited);
            }
        }
        return components;
    }
    vector<vector<int>> createList(vector<vector<int>>& isConnected){
        int n = isConnected.size();
        vector<vector<int>> adjList(n + 1);
        
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                if(i == j){
                    continue;
                }
                if(isConnected[i][j] == 1){
                    adjList[i + 1].push_back(j + 1);
                }
            }
        }
        return adjList;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjList = createList(isConnected);
        return countComponents(adjList);
    }
};