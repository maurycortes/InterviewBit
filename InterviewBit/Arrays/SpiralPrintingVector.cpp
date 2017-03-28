vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	int m =  A.size();
	int n = A[0].size();
	// DO STUFF HERE AND POPULATE result
	    int i, k = 0, l = 0;
 
    while (k < m && l < n)
    {
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i)
        {
            cout << A[k][i] << " ";
        }
        k++;
 
        /* Print the last column from the remaining columns */
        for (i = k; i < m; ++i)
        {
            cout << A[i][n-1] << " ";
        }
        n--;
 
        /* Print the last row from the remaining rows */
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                cout << A[m-1][i] << " ";
            }
            m--;
        }
 
        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                cout << A[i][l] << " ";
            }
            l++;    
        }        
    }
	return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
