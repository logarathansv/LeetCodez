class Solution {
public:
    void dfs(int node, vector<vector<int>>& rooms, vector<bool>& visited){
        visited[node] = true;

        for(auto neigh : rooms[node]){
            if(!visited[neigh]){
                cout<<neigh<<" ";
                dfs(neigh, rooms, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(0, rooms, visited);

        for(auto vi:visited) if(vi == false) return false;

        return true;
    }
};