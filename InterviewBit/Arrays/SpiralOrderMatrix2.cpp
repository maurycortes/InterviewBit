vector<vector<int> > Solution::generateMatrix(int A) {
	int dir = 0;
	vector< vector<int> > matrix(A, vector<int> (A, 0));
	int i = 0, j = 0, k = 1;
	while (k <= A * A)
	{
	    matrix[i][j] = k++;
	    if (dir == 0)
	    {
		    j++;
		    if (j == A || matrix[i][j] != 0) dir = 1, j--, i++;
	    }
	    else if (dir == 1)
	    {
		    i++;
		    if (i == A || matrix[i][j] != 0) dir = 2, i--, j--;
		}
		else if (dir == 2)
		{
			j--;
			if (j < 0 || matrix[i][j] != 0) dir = 3, j++, i--;
		}
		else if (dir == 3)
		{
			i--;
			if (i < 0 || matrix[i][j] != 0) dir = 0, i++, j++;
		}
	}
	return matrix;
}
