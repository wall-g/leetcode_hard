//ltc: 847
//topic: bit manipulation, BFS
class Solution {
public:
    int bfs(int src, vector<vector<int>>& graph, int n){
        queue<pair<int, int>>q;
        map<pair<int, int>, int>mp;
        mp[{src, (1<<src)}] = 1;
        q.push({src, (1<<src)});
        int cnt = 0;
        int dest = (1<<n)-1; 
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                pair<int, int>x = q.front();
                q.pop();
                if(x.second == dest){
                    return cnt;
                }
                for(int i = 0; i < graph[x.first].size(); i++){
                    pair<int, int>temp = {graph[x.first][i], x.second|(1 << graph[x.first][i])};
                    if(mp.find(temp) == mp.end()){
                        mp[temp] = 1;
                        q.push(temp);
                    }
                }  
            }
            cnt++;
        }
        return -1;
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            int temp = bfs(i, graph, n);
            ans = min(temp, ans);
        }
        return ans;
    }
};