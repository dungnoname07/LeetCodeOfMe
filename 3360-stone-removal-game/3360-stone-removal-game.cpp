class Solution {
public:
    bool canAliceWin(int n) {
        int a = 10, win = 0;
        while( n >= a) {
            n -= a;
            a--;
            win = (win + 1)%2;
        }
        if (win == 1) return true;
        return false; 
    }
};