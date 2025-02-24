class Solution {
public:
    vector<vector<int>> graph;
    vector<int> visited;
    int maxIncome = INT_MIN;
    unordered_map<int, int> bobPath;

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        graph.resize(amount.size());
        visited.assign(amount.size(), false);
        
        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        findBobPath(bob, 0); //bob source node, time
        visited.assign(amount.size(), false);
        findAlicePath(0, 0, 0, amount);

        return maxIncome;
    }
    bool findBobPath(int src, int time){
        bobPath[src] = time;
        visited[src] = true;

        if(src == 0){
            return true;
        }
        
        for(auto neighbour : graph[src]){
            if(!visited[neighbour] && findBobPath(neighbour, time + 1)){
                return true;
            }
        }
        bobPath.erase(src);
        return false;
    }
    void findAlicePath(int src, int income, int time, vector<int>& amt){
        visited[src] = true;
        if(bobPath.find(src) == bobPath.end() || time < bobPath[src]){
            income += amt[src];
        }
        else if(time == bobPath[src]){
            income += (amt[src] / 2);
        }
        if(graph[src].size() == 1 && src != 0){
            maxIncome = max(maxIncome, income);
        }
        for(auto neighbour : graph[src]){
            if(!visited[neighbour]){
                findAlicePath(neighbour, income, time+1, amt);
            }
        }
    }
};