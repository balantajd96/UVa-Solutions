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
#define Sort(v) sort(v.begin(),v.end())  
#define Mxe(v)  *max_element(v.begin(),v.end())
#define Mne(v)  *min_element(v.begin(),v.end())
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

char uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
char lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
string intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}

#define MOD 1000000007
#define MAX -1000000007
#define MIN 1000000007

//Code starts from here......

ll fib[100];
void fibonacci()
{
	fib[0] = 1;
	fib[1] = 1;
	for(int i = 2 ; i <= 50 ; i++)
		fib[i] = fib[i-1] + fib[i-2];
}

int main()
{
    // File input and outputs :     Fin ; Fout ;
    
    fibonacci();
    int tc;
	cin >> tc;
    
    while(tc--)
    {
    	int n ;
    	cin >> n;
    	
    	ll ar[n+10];
    	for(int i = 0 ; i < n ; i++)
    		cin >> ar[i];

    	getchar();
    	string str;
    	getline(cin , str);
    	int len = str.size();
    	
    	string s ;
    	for(int i = 0 ; i <= 50 ; i++)
    		s.pb('*');

    	int pos = 0;
    	
    	for(int i = 0 , j = 0; i < n ; i++){
    		for( ; j < len ; j++){
    			if(str[j] >= 'A' && str[j] <= 'Z'){
    				for(int k = 1 ; k < 50 ; k++){
    					if(fib[k] == ar[i]){
    						pos = max(pos,k);
    						s[k] = str[j];
    						break;
    					}
    				}
    				j++;
    				break;
    			}
    		}
    	}
    	
    	for(int i = 1; i <= pos ; i++ ){
    		if(s[i] == '*')
    			cout << " ";
    		else 
    			cout << s[i];
    	}
    	cout << "\n";
    	
    }

    return 0;
}
