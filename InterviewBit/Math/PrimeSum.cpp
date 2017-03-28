vector<int> Solution::primesum(int A) {
        // Generate isPrime List less equal than N
        vector<bool> isPrime(A + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        
        // Sieve of Erastothenes
        for(int i = 2; i <= A; i++) {
            if (!isPrime[i]) continue;
            if (i > A / i) break;
            for (int j = i * i; j <= A; j += i) isPrime[j] = false;
        }
        
        for(int i = 2; i <= A; ++i) {
            if(isPrime[i] && isPrime[A - i]) {
                vector<int> ans;
                ans.push_back(i);
                ans.push_back(A - i);
                return ans;
            }
        } 
        
        vector<int> ans; 
        return ans;
}
