void initializeWindow(const vector<int> &A,int n,int begin,int k,deque<int> &DQ){
    int i=begin;
    while(i<n && i<begin+k)
    {
        if(DQ.empty() || DQ.back()<=A[i])
            DQ.push_back(A[i]);
        i++;
    }
}

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<int> DQ;
    int n=A.size();
    int i=0;
    int p=-1;
    vector<int> ans;
    initializeWindow(A,n,0,B,DQ);
    ans.push_back(DQ.back());
    i+=B;
    while(i<n)
    {
        p=i-B;
        if(A[p]==DQ.front())
            DQ.pop_front();
        if(DQ.empty())
        {
            initializeWindow(A,n,p+1,B,DQ);
            ans.push_back(DQ.back());
        }
        else
        {
            if(A[i]>=DQ.back())
                DQ.push_back(A[i]);
            ans.push_back(DQ.back());
        }
        i++;
    }
    return ans;
}
