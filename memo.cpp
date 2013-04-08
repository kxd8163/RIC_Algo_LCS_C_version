#include <vector>
#include <iostream>

using namespace std;
/*
   int getmax(int &a, int &b) {
   return (a > b)? a : b;
   }
   */

int memo(vector<char> stroka_1, vector<char> stroka_2, unsigned int m, unsigned int n) {

    int sol1, sol2;

    if (m == 0 || n == 0) {
        return 0;
    }
    if ( tbl[m][n] > 0) {
        return tbl[m][n];
    }

    if (stroka_1[m-1] == stroka_2[n-1]) {
        sol1 = memo(stroka_1, stroka_2, m-1, n-1);
        tbl[m][n] = sol1 +1;

        return sol1+1;
    }
    else {
        sol1 = memo(stroka_1, stroka_2, m-1, n);
        sol2 = memo(stroka_1, stroka_2, m, n-1);

        tbl[m][n] = (sol1 >= sol2) ? sol1 : sol2;

        return tbl[m][n];
    }
}
