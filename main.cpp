#include <iostream>
#include <vector>

#include <sstream>
#include <cassert>
using namespace std;
char Scale[]="CKF";
struct Temperature{
        double temp;
        char scale;
};

istream& operator >> (istream& in,Temperature & Temp);

 istream& operator >> (istream& in,Temperature & Temp){
    in>>Temp.temp;
    in>>Temp.scale;}


void test_temperature_input(){
    Temperature Temp;
    string inp="10C";
    istringstream iss(inp);
    iss>>Temp;
    assert(Temp.temp==10);
    assert(Temp.scale=='C');

        istringstream iss1("0K");
    iss1>>Temp;
    assert(Temp.temp==0);
    assert(Temp.scale=='K');

      istringstream iss2("-400F");
    iss2>>Temp;
    assert(Temp.temp==-400);
    assert(Temp.scale=='F');
};

double convert(const Temperature& Temp ,char scale_to){
    double T_Kel;
    T_Kel=Temp.temp;
    switch(Temp.scale){
    case 'C':
        T_Kel+=273;
        break;

    case 'F':
        T_Kel=((9.0/5)*(T_Kel-273)+32);
        break;

    case 'K':
        T_Kel=T_Kel;
        break;

    }

}

int    main() {

    test_temperature_input();


        /*
    size_t count;
    string otvet;
    cerr<<"\n chislo el";
    cin >> count;
    vector<double> el(count);
    cerr<<"\n vvedite "<<count<<" elementov";
    for (size_t i = 0; i < count; i++) {
        cin >> el[i];
    }
    size_t col_count;
    do
    {
        cerr<<"\n chislo stolbtsov";
        cin >> col_count;
        double min = el[0], max = el[0];
        for (double x:el) {
            if (x < min) {
                min = x;
            }
            else if (x > max) {
                max = x;
            }
        }
        vector<size_t> bins(col_count, 0);
        for (double x:el) {
            size_t index = (x - min) / (max - min) * col_count;
            if (x == max) {
                index--;
            }
            bins[index]++;
        }
        for (size_t i = 0; i < col_count; i++) {
            if (bins[i] >= 100)
                cout << "\n" << bins[i] << "|";
            else if (bins[i] >= 10)
                cout << "\n " << bins[i] << "|";
            else
                cout << "\n  " << bins[i] << "|";
            for (size_t k = 0; k < bins[i]; k++) {
                cout << "*";
            }
        }
        cout<<"\n dovolni li vi resultatom\n";
        cin>>otvet;
    }
    while (otvet=="net");*/
    return 0;
}