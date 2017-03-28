bool ispossible(vector<int> &C, long long maxUnitsToPaint, int painter){
    long long temp=maxUnitsToPaint;
    int n=C.size();
    int i=0;
    while(i<n)
    {
        if(painter==0)
            return false;
        if(temp-C[i]<0)
        {
            temp=maxUnitsToPaint;
            painter--;
        }
        else
        {
          temp-=C[i];
          i++;
        }
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C) {
    if(C.size()==0)
        return 0;
    long long left=0, right=LLONG_MAX, mid=B, result=0;
    long long mod=10000003;
    while(left<=right)
    {
        mid=(left+right)>>1;
        if(ispossible(C,(long long)mid/B,A))
        {
            result=mid%mod;
            right=mid-1;
        }
        else
            left=mid+1;
    }
    return (int)result;
}
