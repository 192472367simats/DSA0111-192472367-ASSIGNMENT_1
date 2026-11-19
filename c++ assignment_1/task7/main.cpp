
#include <iostream>
using namespace std;

const long long MIN_BALANCE = 5000;

// Procedural approach
bool proceduralCanTravel(long long balance, long long fare) {
    return balance - fare >= MIN_BALANCE;
}

void proceduralDeduct(long long& balance, long long fare) {
    if (proceduralCanTravel(balance, fare))
        balance -= fare;
    else
        cout << "Procedural: Journey denied\n";
}

// Object-oriented approach
class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long b) : balance(b) {}

    bool canTravel(long long fare) {
        return balance - fare >= MIN_BALANCE;
    }

    void deduct(long long fare) {
        if (canTravel(fare)) {
            balance -= fare;
            cout << "OOP: Fare deducted successfully\n";
        } else {
            cout << "OOP: Journey denied\n";
        }
    }

    long long getBalance() {
        return balance;
    }
};

int main() {
    long long proceduralBalance = 10000;

    proceduralDeduct(proceduralBalance, 2000);

    cout << "Procedural balance: "
         << proceduralBalance << " paise\n";

    SmartCard card(10000);

    card.deduct(2000);

    cout << "OOP balance: "
         << card.getBalance() << " paise\n";

    return 0;
}
