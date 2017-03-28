bool Solution::isPower(int A) {
    if (A == 1)
    {
        return 1;
    }
    double i, a = (double) A;
 
    /*
    bad implementation
    iterate from i=2 to sqrt(A)
      iterate from power=2 to pow(2, power) > A
    - O(sqrt(n) * sqrt(n)) = O(n) ?
     
    for (i = 2; i <= sqrt(A); i++) {
        int power = 2, prod;
        while ((prod = pow(i, power)) <= A) {
            if (prod == A) {
                return 1;
            }
            power++;
        }
    }
    */
     
    /*
     *  better way
     *  start from sqrt(A), down to 2, check ceil( A^(1/i) ) ^ i == A
     *  - O(sqrt(n))
     */
    for (i = ceil(sqrt(a)); i > 1; i--) {
        if (A == pow(ceil(pow(A, 1./i)), i)) {
            return 1;
        }
    }
    return 0;
}
