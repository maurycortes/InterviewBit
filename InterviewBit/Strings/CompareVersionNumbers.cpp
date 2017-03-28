string trim(string A){
    int m=A.length();
    string temp="";
    int i=0;
    while(i<m && A[i]=='0')
        i++;
    if(i==m)
        temp="0";
    else
    {
        for(;i<m;i++)
            temp+=A[i];
    }
    return temp;
}
string number(string A,int &i){
    string temp="";
    while(i<A.length() && A[i]!='.')
    {
        temp+=A[i];
        i++;
    }
    return trim(temp);
}
int Solution::compareVersion(string A, string B) {
    int i=0;
    int j=0;
    string number1="1",number2="1";
    while(i<A.length() || j<B.length())
    {
        number1=number(A,i);
        i++;
        number2=number(B,j);
        j++;
        if(number1.length()==number2.length())
        {
            if(number1>number2)
                return 1;
            else if(number1<number2)
                return -1;
        }
        else
        {
            if(number1.length()>number2.length())
                return 1;
            else return -1;
        }
    }
    return 0;
}


/////////////////////////////////////////////////////////////////////////////////




class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream st1(version1);
        istringstream st2(version2);
        string token;
        vector<int> d1;
        vector<int> d2;
        while (getline(st1,token,'.')){
            stringstream os1;
            os1.str(token);
            int tmp;
            os1 >> tmp;
            d1.push_back(tmp);
        }
        while (getline(st2,token,'.')){
            stringstream os2;
            os2<<token;
            int tmp;
            os2 >> tmp;
            d2.push_back(tmp);
        }
         
        int n1 = d1.size();
        int n2 = d2.size();
         
        for (int i=0;i<min(n1,n2);i++){
            if (d1[i]>d2[i]){ return 1;}
            if (d1[i]<d2[i]){ return -1;}
        }
         
        if (n1<n2){
            for (int i=n1;i<n2;i++){
                if (d2[i]!=0){return -1;}
            }
            return 0;
        }
        if (n1>n2){
            for (int i=n2;i<n1;i++){
                if (d1[i]!=0){return 1;}
            }
            return 0;
        }
        if (n1==n2){return 0;}
    }
};