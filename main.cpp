
#include <iostream>
#include <fstream>
using namespace std;
bool isUsed = false;
pair <bool, uint16_t> p[10000000];
int sieve(int max) {
    int temp = 0;
    int result = 0;
    if (!isUsed)
    {
        for (int i = 1; i < max; i++)
        {
            p[i].first = true;
        }
        for (int j = 2; j <= max; j++)
        {
            p[j - 1].second = temp;
            if (!p[j - 1].first)
            {
                continue;
            }
            else
            {
                temp++;

                for (int i = 2 * j - 1; i < max; i += j)
                    p[i].first = false;
            }
            p[j - 1].second = temp;
        }
    }
    isUsed = true;
    return p[max - 1].second;
}
int main() {
    ofstream out;
    out.open("python.txt");
    ofstream out2;
    out2.open("output.txt");
    out << "import keyboard\n\
import time\n\
time.sleep(2)\n";
    cout << "Choose a mode (1-data for the chart; 2-probability for a specific number; 3-number of primes up to the entered number)" << endl;
    int mode;
    cin >> mode;
    if (mode == 1)
    {
        cout << "OK! Enter the extreme maximum number:";
        int s;
        cin >> s;
        sieve(s);
        for (int i = 2; i <= s; i++)
        {
            out << "keyboard.write(\"" << double(sieve(i)) / i << "\\n\")" << endl << "time.sleep(0.5)" << endl;
            out2 << double(sieve(i)) / i << endl;
            cout << double(sieve(i)) / i << endl;
        }
    }
    else if (mode == 2)
    {
        cout << "OK! Enter number:";
        int s;
        cin >> s;
        cout << double(sieve(s)) / double(s);
    }
    else if (mode == 3)
    {
        cout << "OK! Enter number:";
        int s;
        cin >> s;
        cout << sieve(s);
    }
    else
    {
        cout << "Didn't understand!";
    }

}
