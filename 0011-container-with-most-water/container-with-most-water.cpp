class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxWater=0;

        while(i<j)
        {
            int cap=min(height[i],height[j])*(j-i);
            maxWater=max(cap,maxWater);

            if(height[i]<height[j])
                i++;
            else
                j--;

        }
        return maxWater;

        
    }
};
