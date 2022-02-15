//4: Median of two sorted arrays
//topics: binary search

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int n = nums1.size();
        int m = nums2.size();
        int low = 0;
        int high = n;
        int num = (n+m)/2;
        while(low <= high){
            int mid = (low+high)/2;
            int temp = num-mid;
            int l1 = (mid == 0)?INT_MIN:nums1[mid-1];
            int r1 =  (mid == n)?INT_MAX:nums1[mid];
            int l2 = (temp == 0)?INT_MIN:nums2[temp-1];
            int r2 = (temp == m)?INT_MAX:nums2[temp];
            if(l1 <= r2 && l2 <= r1){
                if((n+m)%2 != 0){
                    return min(r1, r2);
                }else{
                    return (max(l1, l2) + min(r1, r2))/(2*1.00000);
                }
            }else{
                if(r1 < l2){
                    low = mid+1;
                }else if(r2 < l1){
                    high = mid-1;
                }
            }
        }
        return 0.00000;
    }