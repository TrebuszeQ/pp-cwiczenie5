#include <iostream>
#include <string>
#include <utility>

using namespace std;

string read_input_str(const string& msg) {
    string in;
    cout << msg << endl;
    cin >> in;

    return in;
}

bool is_int(const string& str) {
    try { stoi(str); }
    catch (exception e) { return false; }
    return true;
}

int read_int(const string& msg) {
    string n = read_input_str(msg);
    while (true) {
        if (is_int(n)) return stoi(n);
        else cout << "Nieprawidlowa wartosc." << n << endl;
    }
}

int * read_arr_msg(int len, const string& msg) {
    auto* arr = new int[len];

    for (int i = 0; i < len; i++) { arr[i] = read_int(msg); }
    return arr;
}

int * read_arr_msgs(int len, string* msgs) {
    auto* arr = new int[len];
    string* msgs_ptr = msgs;

    for (int i = 0; i < len; i++) { arr[i] = read_int(msgs_ptr[i]); }
    return arr;
}

int* array_min_and_count(int* ptr, int len) {
    auto* result = new int[2];

    int previous_count = 0;
    int count = 0;

    int* arr = ptr;
    int minn = 0;

    for (int i = 0; i < len; i++) {
        if (arr[i] < minn) {
            minn = arr[i];
            count = 0;
        }
        else if (minn == arr[i]) { count++; }
    }

    delete[]arr;
    result[0] = minn;
    result[1] = count;

    return result;
}

int* zadanie1(int len) {
    int* ptr = read_arr_msg(len, "Wprowadz liczbe calkowita.");
    return array_min_and_count(ptr, len);
}

int* sauce_report() {


}

string* set_sauce_msgs(char* sauces, int len) {
    char* sauces_ptr = sauces;
    string msgs = new string[len];
    for (int i = 0; i < len; i++) { msgs[i] = "Wprowadz ilosc sprzedanych pojemnikow sosu " + (string) reinterpret_cast<const char *>(sauces_ptr[i]) + "."; }

    return msgs;
}

int* zadanie2() {
    int len = 5;
    std::string* sauces[] = {"lagodny", "ostry", "kwasny", "slodki", "pikantny"};
    auto* sales = new int[len];
    string* msgs_ptr = set_sauce_msgs(sauces, len);
            int* ptr = read_arr_msgs(len, );

    return
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
                int* res_ptr = zadanie1(9);
                cout << "Wartosc minimalna wynosi " << res_ptr[0];
                cout << "i wystepuje " << res_ptr[1] << " razy." << endl;
                delete[]res_ptr;

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

