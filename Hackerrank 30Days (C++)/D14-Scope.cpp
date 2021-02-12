#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference
{
private:
    vector<int> elements;

public:
    int maximumDifference;

    Difference(vector<int> elements)
    {
        this->elements = elements;
    }

    void computeDifference()
    {
        int min = 100, max = 1;
        for (int i = 0; i < (int)elements.size(); i++)
        {
            if (max < elements[i])
            {
                max = elements[i];
            }
            if (min > elements[i])
            {
                min = elements[i];
            }
        }
        maximumDifference = abs((min - max));
    };

}; // End of Difference class

int main()
{
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++)
    {
        int e;
        cin >> e;

        a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}