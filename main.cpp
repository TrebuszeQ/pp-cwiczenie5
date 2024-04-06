#include <iostream>
#include <string>
#include <utility>
#include <cstring>
#include <list>
#include <random>
#include <cmath>

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

int* read_arr_msg(int len, int arr[], const string& msg) {
    for (int i = 0; i < len; i++) {
        int input = read_int(msg);
        arr[i] = input;
    }

    return arr;
}

int* array_min_and_count(const int* arr, int* result, int len) {
    int count = 0;
    int minn = arr[0];

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

int* zadanie1(const int len) {
    int* arr_ptr = new int[len];
    read_arr_msg(len, arr_ptr, "Wprowadz liczbe calkowita.");

    int* res_ptr = new int[2] {0,0};
    array_min_and_count(arr_ptr, res_ptr, len);

    return res_ptr;
}

class SauceReport {
    private:
    const int len = 5;
    const char* sauces[5]{};
    int* sales;
    int total;
    int min = -1;
    int max = 0;
    list<string> min_sold;
    list<string> max_sold;

    public:
        SauceReport() {
            sales = new int[len];
            sauces[0] = "lagodny";
            sauces[1] = "ostry";
            sauces[2] = "kwasny";
            sauces[3] = "slodki";
            sauces[4] = "pikantny";
        }

        ~SauceReport() {
            free(sales);
        }

        void read_sales() {
            auto it_min = min_sold.begin();
            auto it_max = max_sold.begin();

            for (int i = 0; i < len; i++) {
                string sauce = sauces[i];
                string msg = "Wprowadz ilosc sprzedanych pojemnikow sosu dla sos: " + sauce + ".";

                int sale = read_int(msg);
                if (sale < 0) {
                    while (sale < 0) {
                        cout << "Sprzedaz nie moze byc mniejsza od zera." << endl;
                        sale = read_int(msg);
                    }
                }
                sales[i] = sale;
                set_max_and_min(i);
            }
        }

        void set_max_and_min(int i) {
            if (sales[i] < min || min == -1) {
                min = sales[i];
                min_sold = list<string>{sauces[i]};
            }
            else if(sales[i] == min) min_sold.emplace_back(sauces[i]);

            if (sales[i] > max) {
                max = sales[i];
                max_sold = list<string>{sauces[i]};
            }
            else if (sales[i] == max) max_sold.emplace_back(sauces[i]);
        }


        void report_sales() {
            cout << "Raport sprzedazy sosow:" << endl;
            int total = 0;

            for (int i = 0; i < len; i++) {
                cout << sauces[i] << ": " << sales[i] << "." << endl;
                total += sales[i];
            }

            cout << "Calkowita ilosc sprzedanych sosow wynosi: " << total << "." << endl;

            if (min == max) {
                cout << "Sprzedaz maksymalna i minimalna sa takie same." << endl;
                report_min_or_max(max_sold, false);
            }

            else {
                report_min_or_max(min_sold, true);
                report_min_or_max(max_sold, false);
            }

            cout << endl;
        }

        void report_min_or_max(const list<string>& list, bool minn) const {
            if (!list.empty()) {
                if (minn) cout << "Lista sosow z najmniejsza sprzedaza " << "(" << min << "): ";
                else cout << "Lista sosow z najwieksza sprzedaza " << "(" << max << "): ";

                int counter = 0;

                for(const string& sauce: list) {
                    cout << sauce;
                    if (counter == list.size() - 2) cout << ".";
                    else cout << ", ";
                }
                cout << endl;
            }

            else cout << "Lista sosow jest pusta." << endl;
        }
};

class StandardDeviation {
    public:
        int len{};
        int* arr{};
        double arithmetic_average{};
        double sigma{};
        double gamma{};

        explicit StandardDeviation(int len) {
            this->len = len;
            arr = new int[len];
            set_random_array();
            set_aa();
            set_sigma();
            set_gamma();
        }

        ~StandardDeviation() {
            delete[]arr;
        }

    private:
        void set_random_array() const {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dist(5,30);

            for (int i = 0; i < len; i++) { arr[i] = dist(gen); }
        }

        void set_aa() {
            arithmetic_average = 0;
            for(int i = 0; i < len; i++) {
                auto xi = double(arr[i]);
                arithmetic_average += xi;
            }
            arithmetic_average = arithmetic_average /(double)len;
        }

        void set_sigma() {
            sigma = 0;
            for(int i = 0; i < len; i++) {
                sigma += pow((arr[i] - arithmetic_average), 2);
            }
            sigma = sqrt(((1.0/(double(len) - 1.0)) * sigma));
        }

        void set_gamma() {
//          https://pl.wikipedia.org/wiki/Odchylenie_standardowe
//          https://pl.wikisource.org/wiki/Czynnik_c4
//          c4 dla n = 15 wynosi 0,98232

            double c4 = 0.98232;
            gamma = sigma/c4;
        }
};

int main() {
    while (true) {
        cout << "Opcje:\n";
        cout << "1. Zadanie 1.5.1. - element minimalny tablicy.\n";
        cout << "2. Zadanie 1.5.2. - raport sosowy.\n";
        cout << "3. Zadanie 1.5.3. - odchylenie standardowe\n";
        cout << "4. Wyjscie. \n\n";

        int opt = read_int("Wprowadz numer opcji [od 0 - 5].\n");

        switch (opt) {
            case 1: {
                int* res_ptr = zadanie1(8);
                cout << "Wartosc minimalna wynosi " << res_ptr[0];
                cout << " i wystepuje " << res_ptr[1] << " razy." << endl;
                cout << endl;
                delete[]res_ptr;

                break;
            }

            case 2: {
                SauceReport report = SauceReport();
                report.read_sales();
                report.report_sales();
                break;
            }

            case 3: {
                const int len = 15;
                StandardDeviation deviation = StandardDeviation(len);

                cout << "Standardowe odchylenie wynosi: " << deviation.sigma << endl;
                cout << endl;
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

