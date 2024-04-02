#include <iostream>
#include <string>

using namespace std;

string read_input_str(string msg) {
    string in  = "";
    cout << msg << endl;
    cin >> in;

    return in;
}

bool is_int(string str) {
    try { stoi(str); }
    catch (exception e) { return false; }
    return true;
}

int read_int(string msg) {
    string n = read_input_str(msg);
    while (true) {
        if (is_int(n)) return stoi(n);
        else cout << "Nieprawidlowa wartosc." << n << endl;
    }
}

int * read_arr(int len) {
    int* arr = new int[len];
    for (int i = 0; i < len; i++) { arr[i] = read_int("Wprowadz liczbe calkowita."); }
    return arr;
}

int array_min(int* ptr, int len) {
    int* arr = ptr;
    int minn = 0;
    for (int i = 0; i < len; i++) { minn = minn < arr[i] ? minn : arr[i]; }

    delete[]arr;

    return minn;
}

int zadanie1(int len) {
    int* ptr = read_arr(len);
    return array_min(ptr, len);
}

int main() {
    while (true) {
        cout << "Opcje:\n";
        cout << "1. Zadanie 1.5.1. - element minimalny tablicy\n";
        cout << "2. Zadanie 1.5.2. - wartosc funkcji w punkcie\n";
        cout << "3. Zadanie 1.5.3. - rzut moneta\n";
        cout << "4. Wyjscie. \n\n";

        int opt = read_int("Wprowadz numer opcji [od 0 - 5].\n");

        switch (opt) {
            case 1: {
                int num = zadanie1(9);
                cout << "Wartosc minimalna wynosi " << num << endl;
                break;
            }

            case 2:
                break;

            case 3: {
                break;
            }

            case 4:
                exit(1);

            default:
                cout << "Brak wybranej opcji.\n";
                break;
        }
    }

    return 0;
}

