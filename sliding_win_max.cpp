//239: Sliding Window Maximum
//topics: monotonic dqueue, sliding window
 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>d;
        vector<int>ans;
        for(int i = 0; i < k; i++){
           while(!d.empty() && nums[i] > d.back()){
                d.pop_back();
            }
            d.push_back(nums[i]);
        }
        
        int i = 1, j = k;
        while(j < n){
            ans.push_back(d.front());
            if(nums[i-1] == d.front()){
                d.pop_front();
            }
            
            while(!d.empty() && nums[j] > d.back()){
                d.pop_back();
            }
            d.push_back(nums[j]); 
            i++;
            j++;
        }
        ans.push_back(d.front());
        return ans;
}