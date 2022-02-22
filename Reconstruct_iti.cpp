//332: Reconstruct Itinerary
//topics:dfs
 bool dfs(vector<string>& ans, unordered_map<string, vector<string>>&mp, string depart, int& n){
        if(ans.size() == n+1){
            return true;
        }
        
        if(mp.find(depart) == mp.end()){
            return false;
        }
        
        for(int i = 0; i < mp[depart].size(); i++){
            if(mp[depart][i] != "#"){
                string str = mp[depart][i];
                mp[depart][i] = "#";
                ans.push_back(str);
                if(dfs(ans, mp, str, n)){
                    return true;
                }
                mp[depart][i] = str;
                ans.pop_back();
            }
        }
        return false;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        unordered_map<string, vector<string>>mp;
        
        for(int i = 0; i < tickets.size(); i++){
            mp[tickets[i][0]].push_back(tickets[i][1]);
        }
        
        int n = tickets.size();
        vector<string>ans;
        ans.push_back("JFK");
        dfs(ans, mp, "JFK", n);
        return ans;
        
    }
