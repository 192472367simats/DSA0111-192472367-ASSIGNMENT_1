
#include <iostream>
#include <string>
using namespace std;

class Passenger {
public:
    string name;
    string category;

    Passenger(string n, string c) : name(n), category(c) {}
};

class FareTable {
public:
    int getFare(int zone) {
        switch (zone) {
            case 1: return 1000;
            case 2: return 2000;
            case 3: return 3000;
            default: return 0;
        }
    }
};

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long b) : balance(b) {}

    bool canTravel(long long fare) {
        return balance - fare >= 5000;
    }

    void deduct(long long fare) {
        if (canTravel(fare))
            balance -= fare;
        else
            cout << "Insufficient balance\n";
    }

    long long getBalance() {
        return balance;
    }
};

class Journey {
public:
    int zone;
    bool peak;

    Journey(int z, bool p) : zone(z), peak(p) {}
};

int main() {
    Passenger p("Ravi", "Student");
    SmartCard card(10000);
    FareTable table;
    Journey trip(2, false);

    int fare = table.getFare(trip.zone);

    if (trip.peak)
        fare += fare * 20 / 100;

    cout << "Passenger: " << p.name << '\n';
    cout << "Category: " << p.category << '\n';
    cout << "Fare: Rs " << fare / 100.0 << '\n';

    card.deduct(fare);

    cout << "Remaining balance: Rs "
         << card.getBalance() / 100.0 << '\n';

    return 0;
}
