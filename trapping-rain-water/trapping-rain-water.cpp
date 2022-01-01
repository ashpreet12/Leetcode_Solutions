class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> leftMax(n);
        leftMax[0] = 0;
        for(int i = 1; i < n;i++){
            leftMax[i] = max(leftMax[i - 1], height[i - 1]);
        }
        
        vector<int> rightMax(n);
        rightMax[n - 1] = 0;
        for(int i = n - 2; i >= 0;i --){
            rightMax[i] = max(rightMax[i + 1],height[i + 1]);
        }
        
        int trapped_water = 0;
        for(int i = 0; i < n; i++){
            
            int temp = min(leftMax[i],rightMax[i]) - height[i];
            if(temp > 0){
               trapped_water+= temp; 
            }
        }
        return trapped_water;
    }
};