// fastest.
int hammingWeight(uint32_t n)
{
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((n & (1 << i)) != 0) // only comparing . // makes it much faster. 
            count++;
    }
    return count;
}
// * slower
int hammingWeight(uint32_t n)
{
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        count += n & 1;
        n = n >> 1; // shifting and updaing
    }
    return count;
}