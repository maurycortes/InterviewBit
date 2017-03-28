int Solution::sqrt(int A) {
    long long B=A;
    long long left=0, right=A;
    long long mid;
    long long sq;
    while(left<=right)
    {
        mid=(left+right)>>1;
        sq=mid*mid;
        if(sq==B)
            return (int)mid;
        else if(sq<B)
            left=mid+1;
        else
            right=mid-1;
    }
    return (int)right;
}
