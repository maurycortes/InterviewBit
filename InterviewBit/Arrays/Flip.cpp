vector<int> Solution::flip(string A) {
    int n = A.length();
    vector<int> B(n);
    for(int i = 0; i < n; i ++)
    {
        if(A[i] == '1') B[i] = -1;
        else B[i] = 1;
    }
    pair<int, int> ans = make_pair(INT_MAX, INT_MAX);
    int best_till_now = 0, best_ending_here= 0, l = 0;
    
    for(int i = 0; i< n; i++)
    {
        if (best_ending_here + B[i] < 0)
        {
            l = i + 1;
            best_ending_here = 0;
        }
        else
            best_ending_here += B[i];
        if (best_ending_here > best_till_now)
        {
            best_till_now = best_ending_here;
            ans.first = l;
            ans.second = i;
        }
    }
    if(ans.first==INT_MAX)
        return vector<int>();
        
    vector<int> ret;
    ret.push_back(ans.first+1);
    ret.push_back(ans.second+1);
    
    return ret;
}