struct info{
    int freq,arrived;
};
string Solution::minWindow(string S, string T) {
    unordered_map <char,info> mymap;
    int p=0,q=0;
    int i;
    for(i=0;i<T.length();i++)
    {
        if(mymap.find(T[i])==mymap.end())
        {
            mymap[T[i]].freq=1;
            mymap[T[i]].arrived=0;
        }
        else
            mymap[T[i]].freq+=1;
    }
    int len=0,n=T.length(),N=S.length();
    int minI=0,maxI=0,minLen=INT_MAX;
    while(1)
    {
        if(len<n)
        {
            if(q==N)
                break;
            if(mymap.find(S[q])!=mymap.end())
            {
                mymap[S[q]].arrived+=1;
                if(mymap[S[q]].arrived<=mymap[S[q]].freq)
                    len++;
            }
            q++;
        }
        else if(len==n)
        {
            if(q-p < minLen)
            {
                minLen=q-p;
                minI=p;
                maxI=q;
            }
            if(mymap.find(S[p])!=mymap.end())
            {
                mymap[S[p]].arrived-=1;
                if(mymap[S[p]].freq>mymap[S[p]].arrived)
                    len--;
            }
            p++;
        }
    }
    string ans="";
    for(i=minI;i<maxI;i++)
        ans+=S[i];
    return ans;
}