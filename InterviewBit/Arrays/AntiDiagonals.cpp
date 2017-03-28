//MI VERSION

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int> > result;
    int hSize = A[0].size();
    if(hSize == 1) return A;
    vector<int> aux;
    aux.push_back(A[0][0]);
    result.push_back(aux);
    for(int i=1; i<hSize; i++)
    {
        vector<int> aux;
        for(int x=0, y=i; x<i+1; x++, y--)
        {
            aux.push_back(A[x][y]);
        }
        result.push_back(aux);
    }
    for(int j=1; j<hSize-1; j++)
    {
        vector<int> aux;
        for(int x=j, y=hSize-1; x<hSize; x++, y--)
        {
            aux.push_back(A[x][y]);
        }
        result.push_back(aux);
    }
    vector<int> temp;
    temp.push_back(A[hSize-1][hSize-1]);
    result.push_back(temp);
    return result;
}

//MAS OPTIMA y MEJOOOOOOOOOOOOR

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int i=0,j=0,x,y;
    int n=A.size();
    vector<vector<int>> result;
    vector<int> aux;
    while(i<n)
    {
        x=i;
        y=j;
        while(x<n & y>=0 )
        {
            aux.push_back(A[x][y]);
            x++;
            y--;
        }
    result.push_back(aux);
    aux.clear();
    if(j<n-1)
        j++;
    else 
        i++;
    }
    return result;
}