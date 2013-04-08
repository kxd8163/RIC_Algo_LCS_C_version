//Random string generator

#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

void gen_ACGT01(const int len) {

    static const char alphanum[] = 
                              "01" 
                            "ACGT";
    vector<char> stroka;

    // generate a different init seed every time we
    // generate string
    clock_t seed;
    double cpu_time_seed;
    seed = clock();
    srand(seed);

    for (int i = 0; i < len; ++i) {
        stroka.push_back((char)alphanum[rand() % (sizeof(alphanum))]);
        printf("%c", stroka.at(i));
        }
    stroka.push_back('\0');
}



int main(int argc, char **argv) {
    
    const int n = atoi(argv[1]);
    
    gen_ACGT01(n);
    
    return 0;
}



