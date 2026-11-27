class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        sort(items.begin(),items.end());
        int n = items.size();
        int ans = 0, cur;
        vector<int> bonus (n, 0);
        vector<int> dp(budget+1, 0);
        vector<vector<bool>> check(budget+1, vector<bool> (n, 0));
        for(int i = 0 ; i < n; i++) 
            for(int j = 0; j < n; j++) {
                if(i != j && items[j][0] % items[i][0] == 0)
                    bonus[i] ++;
            }
        for(int i = 0; i <= budget; i++) {
            int ln = -1;
            for(int j = 0; j < n; j++)
                if(i >= items[j][1]) {
                    if(check[i - items[j][1]][j] == 0) {
                        cur = dp[i - items[j][1]] + 1 + bonus[j];
                    }
                    else 
                        cur = dp[i - items[j][1]] + 1;
                    if(dp[i] < cur) {
                        dp[i] = cur;
                        ln = j;
                    }
                }
            if(ln != -1) {
                for(int j = 0; j < n; j++)
                    if(check[i - items[ln][1]][j] == 1)
                        check[i][j] = 1;
                check[i][ln] = 1;
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};