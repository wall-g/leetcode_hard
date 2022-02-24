//132: Palindrome Partitioning II
//topics: dp 
 int func(int i, vector<vector<bool>>&is_palindrome, int& n, vector<int>& dp){
        if(i == n){
            return -1;
        }
        
        if(dp[i] != -1){
           return dp[i]; 
        }
        
        int mini = INT_MAX;
        for(int k = i+1; k <= n; k++){
            if(is_palindrome[i][k-1]){
                mini = min(mini, 1+func(k, is_palindrome, n, dp));
            }
        }
        dp[i] = mini;
        return dp[i];
    }
    
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>>is_palindrome(n, vector<bool>(n, true));
        
        for(int i = 0; i < n; i++){
            is_palindrome[i][i] = true;
        }
        
        for(int j = 1; j < n; j++){
            int i = 0;
            int temp = j;
            while(i < n-j){
                if(s[i] == s[temp]){
                    if(is_palindrome[i+1][temp-1]){
                       is_palindrome[i][temp] = true; 
                    }else{
                        is_palindrome[i][temp] = false;
                    }
                }else{
                    is_palindrome[i][temp] = false;
                }
                temp++;
                i++;
            }
        }
        
        vector<int>dp(n, -1);
        return func(0, is_palindrome, n, dp);
    }