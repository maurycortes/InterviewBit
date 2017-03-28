int Solution::removeElement(vector<int> &A, int B) {
    int n=A.size();
    int i;
    i=0;
    while(i<n && A[i]!=B)
        i++;
    if(i==n)
        return n;
    int p=i+1;
    while(p<n)
    {
        if(A[p]!=B)
        { 
            A[i]=A[p];
            i++;
        }
        p++;
    }
    for(;i<n;i++)
        A.pop_back();
    return A.size();
}
