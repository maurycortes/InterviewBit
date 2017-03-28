void swap(int& a,int &b){
	int c=a;
	a=b;
	b=c;
}

vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(), A.end());  //sort elements
    for(int i=0; i<A.size()-1; i+=2)
    	swap(A[i], A[i+1]);  //swap elements in pairs
    return A;
}