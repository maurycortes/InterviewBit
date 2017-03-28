int Solution::maxSubArray(const vector<int> &A) {
    int result = A[0], sum = 0;
    if(A.size()==1)
        return A[0];
    for(int i = 0; i < A.size(); i++)
    {
        sum = sum + A[i];
        if(sum < A[i])
            sum = A[i];
        if(result < sum)
            result = sum;
    }
    return result;
}