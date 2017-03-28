int Solution::trailingZeroes(int A) {
    int sum = 0;
    while(A / 5 > 0)
    {
        sum += (A / 5);
        A /= 5;
    }
    return sum;
}
