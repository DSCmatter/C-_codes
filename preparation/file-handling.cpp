#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int ch;
    float avg;
    int total = 0;
    int x = 0;

    ifstream fin("testing.txt");

    while (fin >> ch) {
        total += ch;
        x++;
    }

    if (x != 0) {
        avg = static_cast<float>(total) / x;
        cout << avg;

        ofstream fout("test11.txt");
        fout << avg;
    } else {
        cout << "No data found in the file.";
    }

    fin.close();
    return 0;
}
