//Fahad Asif CS5A Roll No.26

#include <bits/stdc++.h>
using namespace std;

bool allFinishedEating(bool phil[], int n)
{
    for (int i = 0; i < n; i++)
        if (!phil[i])
            return false;
    return true;
}

void clearSticks(bool sticks[], int n)
{
    for (int i = 0; i < n; i++)
        sticks[i] = true;
}

int main()
{
    int n;
    bool sticks[30], finishedEating[30];
    cout << "Enter no. of philosophers : ";
    cin >> n;
    clearSticks(sticks, n);
    bool flag = true;
    while (flag)
    {
        cout << "\nNew loop:\n";
        clearSticks(sticks, n);
        flag = false;
        for (int i = 0; i < n; i++)
        {
            if (!finishedEating[i])
            {
                if (sticks[i] && sticks[(i + 1) % 5])
                {
                    sticks[i] = false;
                    sticks[(i + 1) % 5] = false;
                    cout << "Philosopher " << i + 1 << " is eating\n";
                    finishedEating[i] = true;
                    flag = true;
                }
                else
                    cout << "Philosopher " << i + 1 << " is thinking\n";
            }
            else
                cout << "Philosopher " << i + 1 << " finished eating\n";
        }
        if (allFinishedEating(finishedEating, n))
        {
            cout << "\n***ALL FINISHED EATING***\n";
            exit(0);
        }
    }
    cout << "\n***DEADLOCK IS PRESENT***\n";
}
