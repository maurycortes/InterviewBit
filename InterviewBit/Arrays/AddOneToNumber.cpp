vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int carry = 1;
    vector <int> result;
    
    for(int i=A.size()-1; i>=0; i--)
    {
        int sum;
        sum = A[i] + carry;
        carry = sum/10;
        result.push_back(sum%10);
    }
    result.push_back(carry);

    int i = result.size()-1;
    vector<int> ans;
    while(i>=0 && result[i]==0)
    {
        i--;
    }
    while(i>=0)
    {
        ans.push_back(result[i]);
        i--;
    }
    return ans;
}