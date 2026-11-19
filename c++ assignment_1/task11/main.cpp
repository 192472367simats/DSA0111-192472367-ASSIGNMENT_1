
#include <iostream>
using namespace std;

constexpr long long MIN_BALANCE = 5000;
constexpr int PEAK_PERCENT = 20;

enum class Zone {
    Inner = 1,
    Middle = 2,
    Outer = 3
};

class FareTable {
public:
    long long getFare(Zone zone, bool peak) {
        long long fare = 0;

        switch (zone) {
            case Zone::Inner:
                fare = 1000;
                break;

            case Zone::Middle:
                fare = 2000;
                break;

            case Zone::Outer:
                fare = 3000;
                break;
        }

        if (peak)
            fare += fare * PEAK_PERCENT / 100;

        return fare;
    }
};

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long amount) : balance(amount) {}

    bool canTravel(long long fare) const {
        return fare >= 0 &&
               balance - fare >= MIN_BALANCE;
    }

    void deduct(long long fare) {
        if (canTravel(fare)) {
            balance -= fare;
            cout << "Journey approved\n";
        } else {
            cout << "Journey denied\n";
        }
    }

    long long getBalance() const {
        return balance;
    }
};

int main() {
    SmartCard card(10000);
    FareTable table;

    long long fare = table.getFare(Zone::Outer, true);

    cout << "Metro Smart Card System\n";
    cout << "Fare: " << fare << " paise\n";

    card.deduct(fare);

    cout << "Remaining balance: "
         << card.getBalance() << " paise\n";

    return 0;
}
