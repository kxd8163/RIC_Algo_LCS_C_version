#include <vector>
#include <string>

using namespace std;

static int max(int &a, int &b) {
    return (a > b)? a : b;
}

int getLCSLength(vector<char> stroka_1, vector<char> stroka_2) {
    unsigned int m = stroka_1.size();
    unsigned int n = stroka_2.size();
    int i,j;

    int K[2][n+1];

    for (j = 0; j <= n; j++) {
        K[1][j] = 0;
    }
    for (i = 1; i <= m; i++) {
        for (j=0; j <= n; j++)
            K[0][j] = K[1][j];
        
        K[1][0]=0;
        
        for (j = 1; j <= n; j++) {
            if (stroka_1[i-1] == stroka_2[j-1]) {
                K[1][j] = K[0][j-1] + 1;
            }
            else {
                K[1][j] = max( K[0][j], K[1][j-1]);
            }
        }
    }
    return K[1][n];
}

string goHirsch(vector<char> stroka_1, vector<char> stroka_2) {
    unsigned int m = stroka_1.size();
    unsigned int n = stroka_2.size();
    int mid, i, j;
    string c = "";
    string stringi;
    int sub1 = 0;
    int sub2 = 0;           
    if (m == 0) {
        return "";		
    }

    if ( m == 1 ) {
        for ( i = 0; i < n; i++ ) {
            if (stroka_2[i] == stroka_1[0]) {
                vector<char>::iterator it;
                for (it= stroka_1.begin(); it < stroka_1.end(); it++) {
                    stringi.push_back(*it);
                }
                return stringi;
            }
        }
        return "";
    }
 

    int sub = getLCSLength(stroka_1, stroka_2);
    //splitting 1st vector on half
    const int half_size = stroka_1.size();

    vector<char> polovina_1(stroka_1.begin(), stroka_1.begin() + half_size/2-1); 
    vector<char> polovina_2(stroka_1.begin() + half_size/2, stroka_1.end()); 


    vector<char> subvec1;
    vector<char> subvec2;
    //Find a correct split of y
    for (mid = 0; mid < n; mid++) {
        subvec1 = vector<char>(stroka_2.begin(), stroka_2.begin() + mid);
        subvec2 = vector<char>(stroka_2.begin() + mid, stroka_2.end());
        sub1 = getLCSLength( polovina_1, subvec1) ; // LCS of first half
        sub2 = getLCSLength( polovina_2, subvec2 ) ; // LCS of second half

        if ( sub1 + sub2 == sub )
            break;             // Found a correct split of y !!!
    }

    string sol1 = goHirsch( polovina_1, subvec1 );
    string sol2 = goHirsch( polovina_2, subvec2 );
//    string part1(sol1.begin(), sol1.end());
//    string part2(sol2.begin(), sol2.end());
    return (sol1 + sol2);
}
