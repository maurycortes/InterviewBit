int Solution::pow(int x, int n, int d) {
    if(x==0)
        return 0;
    if(n==0)
        return 1;
    long long a=1;
    long long y=x%d;
    if(y<0) y=y+d;
    while(n>0)
    {
        if(n&1)
            a=(a*y)%d;
        y=y*y;
        y=y%d;
        if(y<0)
            y+=d;
        n=n>>1;
    }
    return (int)a;
}
