#include <iostream>

using namespace std;
int* getIntegerArray(int number, int numDigits);
void printArray(int *array, int size);
class Odometer
{
    public:
        Odometer(int numDigits);
        int getCurrentValue();
        int nextValue(int value);
        int prevValue(int value);
        int distDiff(int, int);
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
    int *numArray = getIntegerArray(val, nDigits);
    int pos = 0;
    bool gotPrev = true;
    while (pos < nDigits + 1 && gotPrev) {
        int curr = nDigits  - pos;
        int prev = curr - 1;
        if ( numArray[curr] - 1 > numArray[prev] ) {
            numArray[curr] -= 1;
            gotPrev = false;
        }
        else {
            numArray[curr] = 9 - pos;
        }
        pos++;
    }
    int nextNum = 0;
    for (int i = 1; i < nDigits + 1; i++ ) {
        nextNum = nextNum * 10 + numArray[i];
    }
    return nextNum;
}

int Odometer::nextValue(int val)
{
    int *numArray = getIntegerArray(val, nDigits);
    int pos = 0;
    bool gotNext = true;
    while (pos < nDigits + 1 && gotNext) {
        int curr = nDigits  - pos;
        //int prev = curr - 1;
        if ( numArray[curr] - 1 > numArray[prev] ) {
            numArray[curr] -= 1;
            gotPrev = false;
        }
        else {
            numArray[curr] = 9 - pos;
        }
        pos++;
    }
    int prevNum = 0;
    for (int i = 1; i < nDigits + 1; i++ ) {
        prevNum = prevNum * 10 + numArray[i];
    }
    return prevNum;
}


int Odometer::distDiff(int o1, int o2)
{
    int count = 0;
    while ( o1 > o2 ) {
        o1 = prevValue(o1);
        count++;
    }
    return count;
}
int* getIntegerArray(int number, int numDigits) {
	int *intArr = new int(numDigits + 1);
	int i;

	for (i = numDigits; i > 0; --i) {
		intArr[i] = number % 10;
		number /= 10;
	}
	intArr[0] = 0;
	return intArr;
}
void printArray(int *array, int size) {
	for (int i = 0; i <= size; ++i) {
		cout << i<<"is "<<array[i] << endl;
	}
}
int main()
{
    Odometer odMeter(5);
    cout << "Previous : " << odMeter.prevValue(34569) << endl;
    cout << "Difference : " << odMeter.distDiff(13458, 12345) << endl;
    return 0;
}
