#include <iostream>
#include <vector>

using namespace std;

static int max(int &a, int &b) {
    return (a > b)? a : b;
}


int naive(vector<char> stroka_1, vector<char> stroka_2, unsigned int m, unsigned int n) {
    if (m == 0 || n == 0)
        return 0;
    if(stroka_1[m-1] == stroka_2[n-1]) {
        return 1 + naive(stroka_1, stroka_2, m-1, n-1);
    }
    else {
        return max(naive(stroka_1, stroka_2, m, n-1), 
                naive(stroka_1, stroka_2, m-1, n));
    }
}
