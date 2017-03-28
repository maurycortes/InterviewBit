string Solution::longestCommonPrefix(vector<string> &A) {
    int n = INT_MAX;
    if (A.size() <= 0)
        return "";
    if (A.size() == 1)
        return A[0];
    // get the min length
    for (int i = 0; i < A.size(); i ++)
    {
            n = A[i].length() < n ? A[i].length() : n ;
    }
    for (int i = 0; i < n; i ++)// check each character
    { 
        for (int j = 1; j < A.size(); j ++)
        {
            if (A[j][i] != A[j - 1][i]) // we find a mis-match
            {
                    return A[0].substr(0, i);
            }
        }
    }
    // prefix is n-length
    return A[0].substr(0, n);
}
