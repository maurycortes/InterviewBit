int Solution::maxArea(vector<int> &A) {
    int n=A.size();
    int p=0,q=n-1;
    int maxA=0;
    while(p<q)
    {
        maxA=max(maxA,(min(A[p],A[q])*(q-p)));
        if(A[p]<A[q])
            p++;
        else q--;
    }
    return maxA;
}