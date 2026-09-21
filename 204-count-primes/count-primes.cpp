class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        int half = n / 2;
        vector<char> isPrime(half, 1);
        
        int count = 1; 
        
        int limit = (sqrt(n) - 1) / 2;
        int i = 1; 
        
        for (; i <= limit; ++i) {
            if (isPrime[i]) {
                count++;
                
                int p = 2 * i + 1; 
          
                for (int j = (1LL * p * p) / 2; j < half; j += p) {
                    isPrime[j] = 0;
                }
            }
        }
        for (; i < half; ++i) {
            if (isPrime[i]) {
                count++;
            }
        }
        
        return count;
    }
};