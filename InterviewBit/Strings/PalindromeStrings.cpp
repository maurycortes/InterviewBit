int Solution::isPalindrome(string A) {
    string aux="";
    int sSize = A.length();
    for(int i=0; i<sSize; i++)
    {
        if(int(A[i])>=65 and int(A[i])<=90)
            aux += A[i] + 32;
        if(int(A[i])>=97 and int(A[i])<=122)
            aux += A[i];
        if(int(A[i])>=47 and int(A[i])<=57)
            aux += A[i];
    }
    string aux2="";
    for(int i=aux.length()-1; i>=0; i--)
    {
        aux2 += aux[i];
    }
    return aux == aux2 ? 1 : 0;
}