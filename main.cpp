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

double convert(const Temperature& Temp ,char scale_to) {
    double T_Kel;
    if ((scale_to) == (Temp.scale)) {
        return Temp.temp;
    }
    switch (Temp.scale) {
    case 'C':
        T_Kel = Temp.temp - 273.15;
        break;

    case 'F':
        T_Kel = ((9.0 / 5) * (Temp.temp - 273.15) + 32);
        break;

    case 'K':
        T_Kel = Temp.temp;
        break;

    }
    switch (scale_to) {
    case 'C':
    case 'c':
        return T_Kel - 273.15;
        break;
    case 'K':
    case 'k':
        return T_Kel;
        break;
    case 'F':
    case 'f':
        return ((9.0 / 5) * (T_Kel - 273.15) + 32);
        break;
    }
    bool operator<(const Temperature& lhs, const Temperature& rhs) {
        return convert(lhs, 'K') < convert(rhs, 'K');
    }

    Temperature operator-(const Temperature& lhs, const Temperature& rhs) {
        Temperature ret_temp;
        ret_temp.temp = convert(lhs, 'K') - convert(rhs, 'K');
        ret_temp.scale = 'K';
        return ret_temp;
    }

    Temperature operator/(const Temperature& lhs, const Temperature& rhs) {
        Temperature ret_temp;
        ret_temp.temp = convert(lhs, 'K') / convert(rhs, 'K');
        ret_temp.scale = 'K';
        return ret_temp;
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
        cerr<<"\n";
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
        float maxb;
        double kf;
        maxb=bins[0];
        for (float x:bins)
        {
           if(maxb<x)
               maxb=x;
        }
        kf=1;
        if(maxb>76)
            kf=(double)(1-(maxb-76)/(maxb));

        for (size_t i = 0; i < col_count; i++) {
            if(i>0)
                cout<<"\n";
            if (bins[i] >= 100)
            {
                cout<<  bins[i] << "|";
            }
            else if (bins[i] >= 10)
                cout << " "<< bins[i] << "|";
            else
                cout <<"  " << bins[i] << "|";
            for (size_t k = 0; k < bins[i]*kf; k++) {
                cout << "*";
            }
        }
        cerr<<"\n dovolni li vi resultatom\n";
        cin>>otvet;
    }
    while (otvet=="net");
    */
    return 0;
}