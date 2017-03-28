int Solution::romanToInt(string A) {
    map<char, int> m;  
    m['I'] = 1;  
    m['V'] = 5;  
    m['X'] = 10;  
    m['L'] = 50;  
    m['C'] = 100;  
    m['D'] = 500;  
    m['M'] = 1000;  
    int len = A.length();  
    if(len <= 0)  
        return 0;  
    int result = m[A[len - 1]];  
    for(int i = len - 2; i >= 0; i--)
    {  
        if(m[A[i]] < m[A[i+1]])
            result = result - m[A[i]];  
        else 
            result = result + m[A[i]];  
    }  
    return result; 
}
