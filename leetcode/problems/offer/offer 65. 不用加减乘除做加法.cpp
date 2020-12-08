class Solution
{
public:
    int add(int a, int b)
    {
        return b ? add(a ^ b, (unsigned int)(a & b) << 1) : a;
    }
};