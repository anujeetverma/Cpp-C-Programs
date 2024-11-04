#include <iostream>
using namespace std;

void CashRegisterSystem(int coinDenomination[], int coinLeft[], int balance) {
    int n = 4;  // Number of coin types
    cout << "Coins used to make change: ";
    
    for (int i = n - 1; i >= 0 && balance > 0; --i) {
        while (balance >= coinDenomination[i] && coinLeft[i] > 0) {
            cout << coinDenomination[i] << " ";
            balance -= coinDenomination[i];
            coinLeft[i]--;  // Decrease the count of this coin
        }
    }

    if (balance > 0) {
        cout << "\nUnable to provide exact change. Remaining balance: " << balance << endl;
    } else {
        cout << "\nChange provided successfully!" << endl;
    }
}

int main() {
    int coinDenomination[] = {1, 5, 10, 25};  // Coin values in cents
    int coinLeft[] = {3, 2, 1, 2};            
    int value, cost;
    
    cout << "Enter the value of amount paid: ";
    cin >> value;
    cout << "Enter the cost: ";
    cin >> cost;

    int balance = value - cost;
    
    if (balance > 0) {
        CashRegisterSystem(coinDenomination, coinLeft, balance);
    } else if (balance == 0) {
        cout << "No change is needed!" << endl;
    } else {
        cout << "Insufficient amount paid." << endl;
    }

    return 0;
}