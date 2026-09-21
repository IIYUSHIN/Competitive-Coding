const int MAX_N = 5000000;
int prefixPrimes[MAX_N + 1];
bool initialized = false;

class Solution {
public:
    int countPrimes(int n) {
      
        if (!initialized) {
       
            vector<bool> isPrime(MAX_N + 1, true);
            isPrime[0] = isPrime[1] = false;
            
            for (int i = 2; i * i <= MAX_N; i++) {
                if (isPrime[i]) {
                    for (int j = i * i; j <= MAX_N; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
    
            int count = 0;
            for (int i = 0; i <= MAX_N; i++) {
                if (isPrime[i]) {
                    count++;
                }
                prefixPrimes[i] = count;
            }
            
            initialized = true;
        }
        
        if (n <= 2) return 0;
        
        
        return prefixPrimes[n - 1]; 
    }
};