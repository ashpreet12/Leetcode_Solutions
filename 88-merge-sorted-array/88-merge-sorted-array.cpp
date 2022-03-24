class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int ptr1 = 0;
        int ptr2 = 0;
        vector<int> merged;
        
        while(ptr1 < m && ptr2 < n){
            
            if(nums1[ptr1] < nums2[ptr2]){
                merged.push_back(nums1[ptr1]);
                ptr1++;
            }else{
                merged.push_back(nums2[ptr2]);
                ptr2++;
            }
        }
        while(ptr1 < m){
            merged.push_back(nums1[ptr1]);
            ptr1++;
        }
        
        while(ptr2 < n){
            merged.push_back(nums2[ptr2]);
            ptr2++;
        }
        nums1.clear();
        nums1 = merged;
    }
};