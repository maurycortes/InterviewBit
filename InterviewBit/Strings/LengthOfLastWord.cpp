int Solution::lengthOfLastWord(const string &A) {
    int sz = A.length();
    if (sz==0)
        return 0;
    int res=0;
    for (int i=sz-1; i>=0; i--)
    {
        if (A[i]!=' ')
            res++;
        else
        {
            if (res>0)
                return res; 
        }
    }
    return res;
}














int Solution::lengthOfLastWord(const string &A) {
    int n=A.length();
    int i;
    int current_length=0;
    int last_length=0;
    for(i=0;i<n;i++)
    {
        if(A[i]!=' ')
            current_length++;
        else if(A[i]==' ')
        {
            if(current_length >0)
                last_length=current_length;
            current_length=0;
        }
    }
    if(current_length >0)
        last_length=current_length;
    return last_length;
}