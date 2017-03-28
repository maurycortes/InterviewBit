int Solution::singleNumber(const vector<int> &A) {
        int t1 = 0;
        int t2 = 0;
        int t3 = 0;
         
        for (int i = 0; i < A.size(); i++){
            t1 = t1 ^ A[i];
            t2 = t2 | ((t1^A[i]) & A[i]);
            t3 = ~(t1 & t2);
            t1 = t1 & t3;
            t2 = t2 & t3;
        }
         
        return t1;
}


///////////////////////////////////////////////////////////

int Solution::singleNumber(const vector<int> &A) {
    int i,j;
    int n=A.size();
    int evenCount=0,oddCount=0;
    int ans=0,bit=0,place=1;
    for(i=0;i<32;i++){
        bit=0;
        evenCount=0;
        oddCount=0;
        for(j=0;j<n;j++){
            if(A[j]&place)
                oddCount++;
            else evenCount++;
        }
        if(oddCount%3==0)
            bit=0;
        else bit=1;
        bit=bit<<i;
        ans=ans | bit;
        place=place<<1;
    }
    return ans;
}