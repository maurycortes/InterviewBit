int Solution::reverse(int A) {
    int rev = 0, sign = 1, digit;
    if (A < 0) 
    {
        sign = -1;
        A *= -1;
    }
    while (A > 0)
    {
        digit = A%10;
        // check for overflow here 
        if (rev > (INT_MAX / 10) || (rev == (INT_MAX / 10) && digit > (INT_MAX % 10)))
        {
            return 0;
        }
        rev = rev * 10 + digit;
        A/=10;
    }
    rev *= sign;        
    return rev;
}
