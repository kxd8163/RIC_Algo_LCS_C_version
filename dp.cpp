#include <vector>
#include <iostream>

using namespace std;

static int max(int &a, int &b)
{
    return (a > b)? a : b;
}


int dp( vector<char> stroka_1, vector<char> stroka_2) 
{
   int m = stroka_1.size();
   int n = stroka_2.size();
   std::cout << "m,n" << m << " " << n << endl;
   vector<vector<int> > L;
   L.resize(m+1, vector<int>(n+1));
   int i, j;

   for (i = 0; i < m+1; i++)
       L[i][0] = 0;

   for (j = 0; i < n+1 ; j++)
       L[0][j] = 0;

   for (i=1; i<m+1; i++) {
     for (j=1; j<n+1; j++)
     {
       if(stroka_1.at(i-1) == stroka_2.at(j-1))
           L[i][j] = L[i-1][j-1] + 1;
       else
           L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
//   table = L;
   return L[m][n];
}


string extract(vector<char> stroka_1, vector<char> stroka_2, unsigned const int m, unsigned int const n)
{
	int i = 0;
	int j = 0;
        vector<vector<int> > table;
        table.resize(m+1, vector<int>(n+1));
        string lcs;
	while (i < m && j < n)
	{
		if (stroka_1[i] == stroka_2[j])
		{
			lcs.push_back(stroka_1[i]);
			i++; j++;
		}
		else if (table[i+1][j] >= table[i][j+1])
			i++;
		else
			j++;
	}
	return lcs;
}			
