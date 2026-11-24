class Solution {
public:
    int maxLength(vector<int>& nums) {
        int g, l, p;
        int len = 1;
        for(int i = 0; i < nums.size(); i++) {
            g = nums[i]; l = nums[i]; p = nums[i]; 
            for(int j = i+1; j < nums.size(); j++) {
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);
                p *= nums[j];
                if (g * l == p) {
                    len = max(len, j - i + 1);
                }
                else break;
            }
            if(nums.size() - i <= len) break;
        }
        return len;
    }
};