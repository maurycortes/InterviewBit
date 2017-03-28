vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    vector<int> myvect;
    bool x[n];
    memset(x, false, sizeof(x));
    
    for(int i=0; i<n; ++i)
    {
        if(x[A[i]-1]==true)
            myvect.push_back(A[i]);
        else
            x[A[i]-1]=true;
    }
    
    for(int i=0; i<n; ++i)
    {
        if(x[i]==false)
        {
            myvect.push_back(i+1);
        }
    }
    
    return myvect;
}