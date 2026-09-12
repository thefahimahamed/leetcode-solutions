class Solution {
public:

    int modular(int a, int expo, int phi)
{
    if (expo == 1)
        return a % phi;

    if (expo & 1)
        return ((a % phi) * (modular(a, expo - 1, phi) % phi)) % phi;
    else
    {
        int temp = modular(a, expo / 2, phi) % phi;
        return (temp * temp) % phi;
    }
}
int superPow(int a, vector<int> &b)
{
    int phi = 1140;
    int exponent = 0;
    for (auto &it : b)
    {
        exponent = (exponent * 10 + it) % phi;
    }
    if (exponent == 0)
        exponent = phi;

    a %= 1337;
    int ans = modular(a, exponent, 1337);
    return ans;
}
};