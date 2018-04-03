#include "Temperature.h"

#include <vector>

#include <cassert>
using namespace std;
char Scale[]="CKF";

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

int    main() {

    test_temperature_input();



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

    return 0;
}