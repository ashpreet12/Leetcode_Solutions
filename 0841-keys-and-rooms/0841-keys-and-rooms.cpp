class Solution {
public:
    bool areAllVisited(vector<bool>&visited){
        for(auto visit : visited){
            if(visit == false){
                return false;
            }
        }
        return true;
    }
    void dfs(vector<vector<int>>& rooms,int source,vector<bool>&visited){
        visited[source] = true;
        for(auto x : rooms[source]){
            if(!visited[x]){
                dfs(rooms,x,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,false);
        dfs(rooms,0,visited);
        return areAllVisited(visited);
    }
};