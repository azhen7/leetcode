#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;

        std::vector<int> v;
        v.resize(n + 1);
        v[0] = 1;
        v[1] = 1;
        v[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            v[i] = v[i - 1] + v[i - 2];
        }
        return v[n];
    }
};