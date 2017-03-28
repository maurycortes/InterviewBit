int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a < 0) return gcd(-1 * a, b);
    if (b < 0) return gcd(a, -1 * b);
    if (a > b) return gcd(b, a);
    return gcd(b%a, a);
}
        
int Solution::maxPoints(vector<int> &X, vector<int> &Y) {
    map<pair<int, int>, int> M;
    int ans = 0;
    
    for (int i = 0; i < X.size(); i++)
    {
        M.clear();
        int same = 1, curMax = 0;
        for (int j = i + 1; j < X.size(); j++)
        {
            int xdiff = X[i] - X[j];
            int ydiff = Y[i] - Y[j];
            if (xdiff == 0 && ydiff == 0)
            {
                same++;
                continue;
            }
            if (xdiff < 0)
            {
                xdiff *= -1; 
                ydiff *= -1;
            }
            int g = gcd(xdiff, ydiff);
            M[make_pair(xdiff / g, ydiff / g)]++; 
            curMax = max(curMax, M[make_pair(xdiff / g, ydiff / g)]);
        }
        curMax+=same;
        ans = max(ans, curMax);
    }
    return ans;
}
