#include <bits/stdc++.h>

using namespace std;

void bubble_sort(vector<int> a)
{
    int total_swaps = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {
        // Track number of elements swapped during a    single array traversal
        int numberOfSwaps = 0;

        for (int j = 0; j < (int)a.size() - 1; j++)
        {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                numberOfSwaps++;
            }
        }

        // If no elements were swapped during a traversal, array is sorted
        if (numberOfSwaps == 0)
        {
            break;
        }
        else
        {
            total_swaps += numberOfSwaps;
        }
    }

    cout << "Array is sorted in " << total_swaps << " swaps." << endl;
    ;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[a.size() - 1] << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int a_i = 0; a_i < n; a_i++)
    {
        cin >> a[a_i];
    }
    bubble_sort(a);
    return 0;
}
