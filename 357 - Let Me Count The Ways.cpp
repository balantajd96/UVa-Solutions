/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>

#define pb      push_back
#define Sqr(n)  (n*n)
#define Mex(v)  *max_element(v.begin(),v.end())
#define Men(v)  *min_element(v.begin(),v.end())
#define Fin     freopen("input.txt","r",stdin)
#define Fout    freopen("output.txt","w",stdout)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const double pi = acos(-1.0);

template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}

//Code starts from here......

ll dp[10][32000];

int main()
{
    // File input and outputs :  Fin ; Fout ;

    ll coin[10];

    coin[1] = 1;
    coin[2] = 5;
    coin[3] = 10;
    coin[4] = 25;
    coin[5] = 50;

    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[2][0] = 1;
    dp[3][0] = 1;
    dp[4][0] = 1;
    dp[5][0] = 1;

    for(int i = 1 ; i <= 5 ; i++){
        for(int j = 1 ; j <= 30100; j++){
            if(j >= coin[i])
                dp[i][j] = dp[i-1][j] + dp[i][j - coin[i]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    ll n ;

    while(cin >> n)
    {
        if(dp[5][n] > 1)
            cout << "There are " << dp[5][n]<<" ways to produce "<< n << " cents change.\n" ;
        else
            cout << "There is only " << dp[5][n]<<" way to produce "<< n << " cents change.\n" ;       
    }
    return 0;
}
