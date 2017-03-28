vector<int> Solution::getRow(int A) {
    vector <int> v(A+1,0);
    v[0]=1;
    int pre1, previous;
    for(int i=1;i<A+1;i++){
    	previous=1;
    	for(int j=1;j<i;j++){
    		pre1=v[j];
    		v[j]=v[j]+previous;
    		previous=pre1;
    	}
    	v[i]=1;
    }
    return v;
}