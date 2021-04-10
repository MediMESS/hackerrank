#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void prime(int n)
{
    int nbDiv = 2;
    if (n == 1)
    {
        cout << "Not prime" << endl;
    }
    else if (n == 2)
    {
        cout << "Prime" << endl;
    }
    else
    {
        // cout << "N: " << n << endl;
        for (int i = 3; i <= sqrt(n); i++)
        {
            // cout << "i == " << i << ", ";
            if (n % i == 0)
            {
                // cout << "div " << nbDiv << ": " << i << ", ";
                nbDiv += 2;
            }
        }
        if (nbDiv == 2)
        {
            cout << "Prime" << endl;
        }
        else
        {
            cout << "Not prime" << endl;
        }
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        prime(n);
    }

    return 0;
}
