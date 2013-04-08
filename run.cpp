//Random string generator

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

#include "naive.h"
#include "dp.h"
//#include "memo.h"
#include "linSpace.h"

//int naive(vector<char>, vector<char>, unsigned const int, unsigned int);

vector<char> gen_ACGT01(const unsigned int len) {

    static const char alphanum[] = 
        "01" 
        "ACGT";
    vector<char> stroka;

    // generate a different init seed every lcs we
    // generate string
    clock_t seed;
    seed = clock();
    srand(seed+1);

    for (unsigned int i = 0; i < len; ++i) {
        stroka.push_back(alphanum[rand() % (sizeof(alphanum))]);
        printf("%c", stroka[i]);

    }
//    stroka.push_back('\0');
    printf("\n");
    cout << "size " << stroka.size() << endl;
    return stroka;
}

// constants for error return values
static const int ERR_NUMARGS( 1 );
static const int ERR_ARGFORMAT( 2 );
static const int ERR_FILEACCESS( 3 );

void printUsage(char* program) {
    cerr << "Usage: " << *program << " [function-name[naive][dp][memo]]"
        << " [first-string-length] " 
        << "[second-string-length]" << endl;
}

/////////////////////////// main //////////////////////////////// 

///
/// main function TODO_DOCS_
/// @author Karina DAMICO 
///
/// @param argc  number of command line arguments
/// @param argv  supplied command line arguments, including program name
//		 argv[1] - function to run (naive, dp, memo) 
//		 argv[2] - length of first string
//		 argv[3] - length of second string
/// @returns errorCode  the error Code 
//		0	if no error
//		1	if incorrect number of arguments
//		2	if incorrect argument format

int main(int argc, char **argv) {

    // check for correct number of cmd line arguments
    if(argc != 4) {
        printUsage(argv[0]);
        return(ERR_NUMARGS);
    }

    string function_name = argv[1];
    unsigned const int stringlen1 = atoi(argv[2]);
    unsigned const int stringlen2 = atoi(argv[3]);

    vector<char> stroka_1 = gen_ACGT01(stringlen1);
    vector<char> stroka_2 = gen_ACGT01(stringlen2);

    cout << "running " << argv[1] << " for strings of length: (" 
        << stringlen1 << ", "
        << stringlen2 << "): " << endl; 

    clock_t start, end;
    double cpu_time_used;

    if (function_name == "dp") {
        start = clock();
        cout << "lcs (DP): " <<  dp(stroka_1,stroka_2);
        end = clock();
        cpu_time_used = ((double)(end-start)); // clocks per sec
        cout << " | DP cpu time: " << cpu_time_used << endl; 
    } 
    if (function_name == "dp-string") {
        start = clock();
        cout << "dp-string (): " <<  extract(stroka_1,stroka_2, stroka_1.size(), stroka_2.size());
        end = clock();
        cpu_time_used = ((double)(end-start)); // clocks per sec
        cout << " | dp-string cpu time: " << cpu_time_used << endl; 
    }
    if (function_name == "naive") {
        start = clock();
        cout << "lcs (naive): " << naive(stroka_1,stroka_2, stroka_1.size(),stroka_2.size() );
        end = clock();
        cpu_time_used = ((double)(end-start)); // clocks per sec
        cout << " | NAIVE cpu time: " << cpu_time_used << endl;
    }
/*    if (function_name == "memo") {
        cout << "lcs (memo): " << memo(stroka_1,stroka_2, stringlen1, stringlen2);
    }
*/    if (function_name == "linear") {
        start = clock();
        cout << " lcs (linear): " << getLCSLength(stroka_1,stroka_2);
        end = clock();
        cpu_time_used = ((double)(end-start)); // clocks per sec
        cout << " | LINEAR cpu time: " << cpu_time_used << endl;
    }
    if (function_name == "linear-string") {
        start = clock();
        cout << "lcs (linear-string): " << goHirsch(stroka_1,stroka_2);
        end = clock();
        cpu_time_used = ((double)(end-start)); // clocks per sec
        cout << " | LINEAR-STRINGcpu time: " << cpu_time_used << endl;
    }
   

    return 0;
}
