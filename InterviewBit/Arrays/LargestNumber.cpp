int comp(string a, string b){
    return a+b > b+a;
}

string Solution::largestNumber(const vector<int> &A) {
    vector <string> aux;
    string result="";
    bool Allzero = true;
    
    for(int i=0; i<A.size(); i++)
    {
        aux.push_back(to_string(A[i]));
        if(A[i]!=0)
            Allzero = false;
    }
    if(Allzero)
        return "0";
    sort(aux.begin(), aux.end(), comp);
    
    for(int i=0; i<aux.size(); i++)
    {
        result+=aux[i];
    }
    return result;
}