#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Chislo {
protected:
    long number;

public:
    Chislo() : number(0) {}

    Chislo(long n) {
        if (n < 0) n = 0;
        number = n;
    }

    virtual ~Chislo() {}

    virtual long long factorial(long n) {
        if (n < 0) return 0;
        long long result = 1;
        for (long i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    long getNumber() const {
        return number;
    }
};

class Matrix : public Chislo {
private:
    vector<long> arr;

public:
    Matrix(long n) : Chislo(n) {
        if (number > 100) number = 100;
        arr.resize(number);
    }

    ~Matrix() {}

    void input() {
        for (long i = 0; i < number; i++) {
            long value;
            cout << "Enter positive integer [" << i << "]: ";
            while (!(cin >> value) || value < 0) {
                cout << "Invalid input. Try again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            arr[i] = value;
        }
    }

    void process(Chislo* ptr) {
        cout << "\nFactorials:\n";
        for (long i = 0; i < number; i++) {
            cout << arr[i] << " -> " << ptr->factorial(arr[i]) << endl;
        }
    }
};

int main() {
    long size;

    cout << "Enter size of array (1 - 100): ";
    while (!(cin >> size) || size <= 0 || size > 100) {
        cout << "Invalid size. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Matrix m(size);
    m.input();

    Chislo* ptr = &m;
    m.process(ptr);

    return 0;
}