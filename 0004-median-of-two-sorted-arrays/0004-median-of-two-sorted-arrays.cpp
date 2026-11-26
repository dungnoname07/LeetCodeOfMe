class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans;
        int s = n + m;
        int i = 0, j = 0;
        while(i + j < s/2+1) {
            if (i == n) {
                ans.push_back(nums2[j]);
                j++;
            }
            else if (j == m) {
                ans.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            }
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        if(s == 0)
            return 0;
        if(s%2 == 0)
            return (double) (ans[s/2] + ans[s/2-1])/2;
        return (double) ans[s/2];
    }
};