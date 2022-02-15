//76: Minimum Window Substring
string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m > n){
            return "";
        }
        unordered_map<char, int>mp;
        for(int i = 0; i < m; i++){
            mp[t[i]]++;
        }
        int need = mp.size();
        int i = 0, j = 0;
        int have = 0;
        unordered_map<char, int>temp;
        int first = -1, second = -1;
        int mini = INT_MAX;
        while(j < n){
            temp[s[j]]++;
            if(temp[s[j]] == mp[s[j]]){
                have++;
            }
            
            while(have == need){
                int l = j-i+1;
                if(l < mini){
                    mini = l;
                    first = i;
                    second = j; 
                }
                temp[s[i]]--;
                if(temp[s[i]] == mp[s[i]]-1){
                    have--;
                }
                i++;
            }
            
            j++;
        }
        string ans = "";
        if(first != -1 && second != -1){
            for(int i = first; i <= second; i++){
                ans += s[i];
            }   
        }
        return ans;
}

