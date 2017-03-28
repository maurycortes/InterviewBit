string expandAroundCenter(string s, int c1, int c2) {
    int l = c1, r = c2;
    int n = s.length();
    while (l >= 0 && r <= n-1 && s[l] == s[r])
    {
        l--;
        r++;
    }
    return s.substr(l+1, r-l-1);
}

string Solution::longestPalindrome(string A) {
    int n = A.length();
    if (n == 0) return "";
    string longest = A.substr(0, 1);  // a single char itself is a palindrome
    for (int i = 0; i < n-1; i++)
    {
        string p1 = expandAroundCenter(A, i, i);
        if (p1.length() > longest.length())
        longest = p1;
 
        string p2 = expandAroundCenter(A, i, i+1);
        if (p2.length() > longest.length())
        longest = p2;
    }
    return longest;
}



////////////////////////////////////////////////////////////////////////

string Solution::longestPalindrome(string A) {
   int i,j;
    int n=A.length();
    if(n==1)
        return A;
    string B="";
    int p,q,l=0,start,end;
    for(i=0;i<n-1;i++){
        p=q=i;
        while(p>=0 && q<n && A[p]==A[q]){
            if(q-p+1 > l){
                l=q-p+1;
                start=p;
                end=q;
            }
            p--;q++;
        }
        if(B.length()<l){
            B="";
            for(j=start;j<=end;j++)
                B+=A[j];
        }
        if(A[i]==A[i+1]){
            p=i;q=i+1;
            while(p>=0 && q<n && A[p]==A[q]){
                if(q-p+1 > l){
                    l=q-p+1;
                    start=p;
                    end=q;
                }
                p--;q++;
            }
            if(B.length()<l){
                B="";
                for(j=start;j<=end;j++)
                    B+=A[j];
            }
        }
    }
    return B;
}

////////////////////////////////////////////////////////////// MANACHER


1 public class Manacher {
2 
3     public Manacher(String s) {
4         
5         char[] T = new char[s.length()*2 + 3];
6         T[0] = '$';
7         T[s.length()*2 + 2] = '@';
8         for (int i = 0; i < s.length(); i++) {
9             T[2*i + 1] = '#';
10              T[2*i + 2] = s.charAt(i);
11          }
12          T[s.length()*2 + 1] = '#';
13          
14          
15          int[]  P = new int[T.length];
16          int center = 0, right = 0;
17          
18          for (int i = 1; i < T.length-1; i++) {
19              int mirr = 2*center - i;
20  
21              if (i < right)
22                  P[i] = Math.min(right - i, P[mirr]);
23              
24            while (T[i + (1 + P[i])] == T[i - (1 + P[i])])
25                  P[i]++;
26  
27              if (i + P[i] > right) {
28                  center = i;
29                  right = i + P[i];
30              }
31          }
32          
33          int length = 0;    
34          center = 0;    
35          for (int i = 1; i < P.length-1; i++) {
36              if (P[i] > length) {
37                  length = P[i];
38                  center = i;
39              }
40          }
41          System.out.println(s.substring((center - 1 - length) / 2, (center - 1 + length) / 2));
42  
43      }
44      
45      public static void main(String[] args) {
46          String s = "abababa" ;
47          Manacher manacher = new Manacher(s);
48      }
49  }

