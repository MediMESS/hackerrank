#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print_array(int arr[])
{
    for (int i = 0; i < 3; i++)
    {
        cout << "arr[" << i << "]: " << arr[i] << endl;
    }
}

int count_fine(int returned_date[], int due_date[])
{
    // 0: Day, 1: month, 2: Year
    // Compare year
    if (returned_date[2] > due_date[2])
    {
        return 10000;
    }
    else if (returned_date[1] > due_date[1] && returned_date[2] == due_date[2])
    {
        int months_late = returned_date[1] - due_date[1];
        return 500 * months_late;
    }
    else if (returned_date[0] > due_date[0] && returned_date[1] == due_date[1] && returned_date[2] == due_date[2])
    {
        int days_late = returned_date[0] - due_date[0];
        return 15 * days_late;
    }
    else
    {
        return 0;
    }
}
int main(int argc, char *argv[])
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int returned_date[3], due_date[3], index, val;

    for (int i = 0; i < 6; i++)
    {
        cin >> val;
        if (i > 2)
        {
            index = i % 3;
            due_date[index] = val;
        }
        else
        {
            returned_date[i] = val;
        }
        /* code */
    }
    // cout << "returned_date" <<endl;
    // print_array(returned_date);
    // cout << "due_date" <<endl;
    // print_array(due_date);
    cout << count_fine(returned_date, due_date) << endl;

    return 0;
}
