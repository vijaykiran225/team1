#include <iostream>

using namespace std;

class Odometer
{
    public:
        Odometer(int numDigits);
        int getCurrentValue();
        int nextValue(int value);
        int prevValue(int value);
        int distDiff(Odometer, Odometer);
        bool checkAscending(int num);

    private:
        int nDigits;
        int *digitArr;
        int currValue;
};

int getFirstValue()
{
    return 12345;
}

Odometer::Odometer(int numDigits)
{
    nDigits = numDigits;
    currValue = getFirstValue();
}
int Odometer::prevValue(int val)
{
    int numArray[] = {0, 3, 5, 7, 8, 9};
    int pos = 0;
    bool flag = true;
    while (pos < nDigits && flag) {
        int curr = nDigits - pos - 1;
        int prev = curr - 1;
        if ( numArray[curr] - 1 > numArray[prev] ) {
            numArray[curr] -= 1;
            flag = false;
        }
        else {
            numArray[curr] = 9 - pos;
        }
        pos++;
    }
    int nextNum = 0;
    for (int i = 1; i < nDigits; i++ ) {
        nextNum = nextNum * 10 + numArray[i];
    }
    return nextNum;
}


int main()
{
    Odometer odMeter(6);
    cout << "Previous : " << odMeter.prevValue(12345) << endl;
    return 0;
}
