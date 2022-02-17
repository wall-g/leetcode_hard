    //ltc: 1886 Number of Ways to Rearrange Sticks With K Sticks Visible
    //topics: dp

    //basically we are taking each element from 1 to n-1 except last one as our last sick and
    //calling our recursive function func(n-1,k);
    //for last stick it will be func(n-1,k-1);
    //base case: when n = k and when n = 0 or k = 0


    //---top-bottom
    int m = 1e9+7;
    long func(int n, int k, vector<vector<long>>&dp){
        if(n == k) return 1;
        if(n == 0 || k == 0) return 0;
        if(dp[n][k] != -1){
            return dp[n][k];
        }
        dp[n][k] = (((n-1)%m*1L*func(n-1, k, dp)%m)%m + func(n-1, k-1, dp)%m)%m;
        return dp[n][k];
    }
    
    int rearrangeSticks(int n, int k) {
        vector<vector<long>>dp(n+1, vector<long>(k+1, -1));
        return func(n, k, dp);
    }


    //---bottom-up
    int m = 1e9+7;
    int rearrangeSticks(int n, int k) {
        vector<long>prev(k+1, 0);
        vector<long>vec(k+1);
        for(int i = 1; i <= n; i++){
            vec[0] = 0;
            for(int j = 1; j <= k; j++){
                if(i == j){
                    vec[j] = 1;
                }else{
                    vec[j] = ((i-1)%m*1L*prev[j]%m + prev[j-1]%m)%m;
                }
            }
            prev = vec;
        }
        return vec[k];
    }