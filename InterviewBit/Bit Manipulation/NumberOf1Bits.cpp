int Solution::numSetBits(unsigned int A) {
    int count=0;
    unsigned int bit=1;
    int i;
    for(i=0;i<33;i++)
    {
        if(bit & A)
            count++;
        bit=bit<<1;
    }
    return count;
}
