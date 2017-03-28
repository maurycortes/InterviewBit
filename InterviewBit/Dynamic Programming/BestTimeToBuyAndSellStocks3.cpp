int Solution::maxProfit(const vector<int> &prices) {
    int n = prices.size();
    if (n < 2)
        return 0;
    int *profits1 = new int[n];
    int *profits2 = new int[n];
    memset(profits1, 0, sizeof(int) * n);
    int ret = 0;
    int minPrice = prices[0];
    for (int i = 1; i < n; ++i)
    {
        minPrice = min(minPrice, prices[i]);
        profits1[i] = max(profits1[i - 1], prices[i] - minPrice);
    }
    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        maxPrice = max(maxPrice, prices[i]);
        profits2[i] = max(profits2[i + 1], maxPrice - prices[i]);
    }
    for (int i = 0; i < n; ++i)
        ret = max(ret, profits1[i] + profits2[i]);
     
    delete [] profits1;
    delete [] profits2;
    return ret;
}
