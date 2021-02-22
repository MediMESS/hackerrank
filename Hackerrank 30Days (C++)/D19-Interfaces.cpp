#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class AdvancedArithmetic
{
public:
    virtual int divisorSum(int n) = 0;
};
class Calculator : public AdvancedArithmetic
{
public:
    int divisorSum(int n)
    {
        int sum = n + 1;
        if (n == 2)
        {
            return 3;
        }
        if (n == 1)
        {
            return 1;
        }

        //cout << "sqrt(" << n << ") = " << round(sqrt(n)+1) << endl;
        //cout << n << "/2" << "- 1 = " << n/2-1 << endl;
        for (int i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                //cout << "i: " << i << ", " << n <<"/" << i << ": " << n/i << endl;
                //cout << "sum = " << sum << " + " << i << " + " << n/i << endl;
                sum += i;
            }
        }
        return sum;
    }
};

int main()
{
    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator();
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n"
         << sum;
    return 0;
}