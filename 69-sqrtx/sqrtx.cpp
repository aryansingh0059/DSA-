class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        for (int i = 1; i <= x; i++) {
            long long square = (long long)i * i;

            if (square == x) {
                return i;
            }
            if (square > x) {
                return i - 1;
            }
        }
        return 0;
    }
};