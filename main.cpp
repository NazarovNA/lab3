#include "Temperature.h"

#include <vector>

#include <cassert>
using namespace std;
char Scale[]="CKF";

int    main() {

    size_t count;
    string otvet;
    cerr<<"\n chislo el";
    cin >> count;
    vector<Temperature> el(count);
    cerr<<"\n vvedite "<<count<<" elementov";
    for (size_t i = 0; i < count; i++) {

        cin >> el[i];
        if (cin.fail()) {return -1;}

        convert(el[i],'K');
    }
    size_t col_count;
    do
    {
        cerr<<"\n chislo stolbtsov";
        cin >> col_count;
        cerr<<"\n";
        double  min = el[0].temp, max = el[0].temp;
        for (Temperature x:el) {
            if (x.temp < min) {
                min = x.temp;
            }
            else if (x.temp > max) {
                max = x.temp;
            }
        }
        vector<size_t> bins(col_count, 0);
        for (Temperature x:el) {
            size_t index = (x.temp - min) / (max - min) * col_count;
            if (x.temp == max) {
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