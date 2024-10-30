#include <iostream>
using namespace std;

int sum(int arr[], int start, int end);

void verifier(int *arr, int idealWt)
{
    for (int i = 0; i < 16; i++)
    {
        if (arr[i] != idealWt)
        {
            cout << "coin " << i << " is a counterfeit coin " << endl;
        }
    }
}

int ukverifiy(int arr[], int l, int h)
{
    while (l < h)
    {
        int m = (l + h) / 2;
        if (sum(arr, l, m) < sum(arr, m + 1, h))
            h = m;
        else
            l = m + 1;
    }
    return l;
}

int sum(int arr[], int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int arr[16];
    for (int i = 0; i < 16; i++)
    {
        cout << "Enter the weight of coin " << i + 1 << ": ";
        cin >> arr[i];
    }
    int idealWt;
    cout << "Enter the value of the ideal weight of the coin: ";
    cin >> idealWt;
    verifier(arr, idealWt);

    // Example of using ukverify function
    int counterfeitIndex = ukverifiy(arr, 0, 15);
    cout << "The counterfeit coin is likely at index: " << counterfeitIndex << endl;
    return 0;
}