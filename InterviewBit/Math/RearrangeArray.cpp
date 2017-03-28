void Solution::arrange(vector<int> &A) {
    int N = A.size();
    for(int i = 0; i < N; ++i)
    {
        A[i] = A[i] + (A[A[i]]%N) * N;
    }

    for(int i = 0; i < N; ++i)
    {
        A[i] = A[i] / N;
    }
}
