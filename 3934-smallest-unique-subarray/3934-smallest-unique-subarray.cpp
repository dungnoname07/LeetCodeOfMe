class Solution {
    using ull = unsigned long long;
    static const ull m1 = 1e9+7, m2 = 998244353, b = 100003;
    vector<ull> h1, h2, p1,p2;
    ull get(int l, int r) {
        ull a = (h1[r] + m1 - h1[l] * p1[r-l] % m1) % m1;
        ull b = (h2[r] + m2 - h2[l] * p2[r-l] % m2) % m2;
        return (a << 32) | b;
    }
    bool check(int n, int l) {
        unordered_map<ull, int> cnt;
        for (int i = 0; i + l <= n; i++) cnt[get(i, i + l)]++;
        for (auto& [k,v] : cnt)
            if (v == 1) return true;
        return false;
    }
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        h1.assign(n+1, 0);
        h2 = h1;
        p1.assign(n+1, 1);
        p2 = p1;
        for(int i = 0; i < n; i++) {
            ull x = (ull)(nums[i] % m2 + m2) % m2 + 1;
            h1[i+1] = (h1[i] * b + x) % m1;
            p1[i+1] = p1[i] * b % m1; 
            h2[i+1] = (h2[i] * b + x) % m2;
            p2[i+1] = p2[i] * b % m2;
        }
        int lo = 1, hi = n;
        while(lo < hi) {
            int mid = (lo + hi)/2;
            if (check(n, mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};