int searchRangeOne(const vector<int> &A, int B)
{
    int left=0, right=A.size()-1;
    long long mid;
    int pivot1=0;
    while(left<=right)
    {
        mid=(left+right)/2;

        if(B==A[mid])
        {
            if(mid>0)
            {
                if(B>A[mid-1]) 
                {
                    pivot1=mid;
                    return pivot1;
                }
                else
                    right=mid-1;
            }
            if(mid==0)
            {
                pivot1=mid;
                return pivot1;
            }
        }
        else if(A[mid]<B)
            left=mid+1;
        else
            right=mid-1;
    }
    return -1;
}
int searchRangeTwo(const vector<int> &A, int B)
{
    int left=0, right=A.size()-1;
    long long mid;
    int pivot2=0;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(B==A[mid])
        {
            if(mid<A.size()-1)
            {
                if(B<A[mid+1])
                {
                    pivot2=mid;
                    return pivot2;
                }
                else
                    left=mid+1;
            }
            if(mid==A.size()-1)
            {
                pivot2=mid;
                return pivot2;
            }
        }
        else if(A[mid]<B)
            left=mid+1;
        else
            right=mid-1;
    }
    return -1;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int left=0, right=A.size()-1;
    long long mid;
    vector<int> result, aux;
    if(A.size()==1)
    {
        result.push_back(0);
        result.push_back(0);
        return result;
    }
    //for(int j=A.size(); j>=0; j--)
        //aux.push_back(A[j]);
    int pivot1 = searchRangeOne(A, B);
    int pivot2 = searchRangeTwo(A, B);
    result.push_back(pivot1);
    result.push_back(pivot2);
    return result;
}
