class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> large;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {

             
                k--;

                if (k == 0)
                    return i;

                if (i != n / i) {
                    large.push_back(n / i);
                }
            }
        }
        for (int i = large.size() - 1; i >= 0; i--) {
            k--;

            if (k == 0)
                return large[i];
        }

        return -1;
    }
};