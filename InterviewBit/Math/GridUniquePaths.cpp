int Solution::uniquePaths(int A, int B) {
    long long result = 1;
    for (int i = B; i < (A + B - 1); i++)
    {
        result *= i;
        result /= (i - B + 1);
    }
    return (int)result;
}
