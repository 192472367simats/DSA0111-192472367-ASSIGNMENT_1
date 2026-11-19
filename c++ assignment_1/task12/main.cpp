
#include <iostream>
#include <algorithm>
using namespace std;

enum class Zone {
    Inner = 0,
    Middle = 1,
    Outer = 2,
    Airport = 3
};

constexpr long long FARES[] = {
    1000, 2000, 3000, 6000
};

constexpr int PEAK_PERCENT = 20;
constexpr int WEEKEND_DISCOUNT = 10;
constexpr long long MIN_BALANCE = 5000;

class MonthlyPass {
private:
    Zone zone1;
    Zone zone2;

public:
    MonthlyPass(Zone a, Zone b)
        : zone1(a), zone2(b) {}

    bool allows(Zone zone) const {
        return zone == zone1 || zone == zone2;
    }
};

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long b) : balance(b) {}

    bool canTravel(long long fare) const {
        return balance - fare >= MIN_BALANCE;
    }

    void deduct(long long fare) {
        if (canTravel(fare)) {
            balance -= fare;
            cout << "Journey approved\n";
        } else {
            cout << "Insufficient balance\n";
        }
    }

    long long getBalance() const {
        return balance;
    }
};

long long calculateFare(
    Zone zone, bool peak, bool weekend
) {
    int index = static_cast<int>(zone);

    if (index < 0 || index > 3)
        return -1;

    long long fare = FARES[index];

    // Weekend discount takes priority over peak surcharge.
    if (weekend) {
        fare -= fare * WEEKEND_DISCOUNT / 100;
    } else if (peak) {
        fare += fare * PEAK_PERCENT / 100;
    }

    return fare;
}

int main() {
    SmartCard card(20000);

    MonthlyPass pass(Zone::Inner, Zone::Middle);

    cout << "UPDATED METRO FARE SYSTEM\n";
    cout << "-------------------------\n";

    // Airport journey during peak hours.
    long long airportFare =
        calculateFare(Zone::Airport, true, false);

    cout << "Airport peak fare: "
         << airportFare << " paise\n";

    card.deduct(airportFare);

    // Outer zone journey on a weekend.
    long long weekendFare =
        calculateFare(Zone::Outer, true, true);

    cout << "Outer weekend fare: "
         << weekendFare << " paise\n";

    card.deduct(weekendFare);

    // Monthly pass test.
    if (pass.allows(Zone::Inner))
        cout << "Inner zone: Monthly pass accepted\n";

    if (pass.allows(Zone::Airport))
        cout << "Airport: Monthly pass accepted\n";
    else
        cout << "Airport: Monthly pass not valid\n";

    cout << "Final balance: "
         << card.getBalance() << " paise\n";

    return 0;
}
