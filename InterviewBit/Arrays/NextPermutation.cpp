void Solution::nextPermutation(vector<int> &A) {
        int sz = A.size();
        int k = -1;
        int l;
        //step1
        for(int i=0; i<sz-1; i++)
        {
            if(A[i] < A[i+1])
            {
                k=i;
            }
        }
        if(k == -1)
        {
            sort(A.begin(), A.end());
            return;
        }
         
        //step2
        for(int i=k+1; i<sz; i++)
        {
            if(A[i] > A[k])
            {
                l=i;
            }
        }
        //step3        
        int tmp = A[l];
        A[l] = A[k];
        A[k] = tmp;
        //step4
        reverse(A.begin()+k+1, A.end());
}