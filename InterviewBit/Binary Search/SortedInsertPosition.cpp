int Solution::searchInsert(vector<int> &A, int B) {
    int left=0; 
    int right=A.size()-1;
    int mid;
 
    while(left <= right)
    {
        mid = (left+right)/2;

        if(B > A[mid])
            left=mid+1;
        else if(B < A[mid])
            right=mid-1;
        else
            return mid;
    }
    return left;
}
