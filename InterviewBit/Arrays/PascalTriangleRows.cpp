vector<vector<int> > Solution::generate(int A) {
    vector<vector<int> > myvect;
    vector<int> minivect;
    if(A<1)
        return myvect;
    minivect.push_back(1);
    myvect.push_back(minivect);
        if(A==1)
            return myvect;
    minivect.push_back(1);
    myvect.push_back(minivect);
        if(A==2)
            return myvect;
    for(int i=2; i<A; i++)
    {
        vector<int> temp;
        temp.push_back(1);
        for(int j=1; j<i; j++)
            temp.push_back(myvect[i-1][j]+myvect[i-1][j-1]);
        temp.push_back(1);
        myvect.push_back(temp);
    }
    return myvect;
}