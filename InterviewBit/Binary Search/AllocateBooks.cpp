bool isPossible(vector<int> A,int B,long long c){
    int n=A.size();
    long long temp=c;
    long long i=0;
    while(i<n)
    {
        if(B==0)
            return false;
        else if(temp-A[i] <0)
        {
            B--;
            temp=c;
        }
        else
        {
            temp-=A[i];
            i++;
        }
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    long long left, right, mid, result=-1;
    if(A.size()<B)
        return -1;
    left=0, right=LLONG_MAX;
    while(left <= right)
    {
        mid=(left+right)>>1;
        if(isPossible(A,B,mid))
        {
            result=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }
    return (int)result;
}
