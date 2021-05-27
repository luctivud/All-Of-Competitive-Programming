//  J A I  S H R E E  R A M  //

#include <bits/stdc++.h>

#pragma GCC optimize "trapv"
// #pragma GCC optimize ("Ofast")
// // #pragma GCC target ("fpmath=sse,sse2")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize ("-ffloat-store")


using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;

#define        forn(I7, E4)    for(lld I7=0ll; I7 < E4; (I7)+=1ll)
#define       forn1(I7, E4)    for(lld I7=1ll; I7 < E4+1; (I7)+=1ll)
#define              len(v)    ((int)((v).size()))
#define              all(x)    (x).begin(), (x).end()
#define             rall(x)    (x).rbegin(), (x).rend()
#define                  f1    first
#define                  s2    second

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type >
ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cout << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << H << ", "; dbg_out(T...);}
#define _____error_____(...) cout << #__VA_ARGS__ << " : ", dbg_out(__VA_ARGS__)

const lld d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const lld d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};


const long double EPS = 1e-6;
lld TempVar, mod, MOD;


/*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/


// matrix exponentiation snippet::
// // courtesy Ashishgup3 via Github





lld add(lld a, lld b) {
    lld res = a + b;
    if(res >= MOD) return res - MOD;
    return res;
}

lld mult(lld a, lld b) {
    long long res = a;
    res *= b;
    if(res >= MOD) return res % MOD;
    return res;
}



const lld SZ = 2; // size of MaGiC 

struct matrix {
    lld MaGiC[SZ][SZ];

    void reset() {
        memset(MaGiC, 0, sizeof(MaGiC));
    }

    void makeiden() {
        reset();
        for(lld i=0;i<SZ;i++) {
            MaGiC[i][i] = 1;
        }
    }

    matrix operator + (const matrix &o) const {
        matrix res;
        for(lld i=0;i<SZ;i++) {
            for(lld j=0;j<SZ;j++) {
                res.MaGiC[i][j] = add(MaGiC[i][j], o.MaGiC[i][j]);
            }
        }
        return res;
    }

    matrix operator * (const matrix &o) const {
        matrix res;
        for(lld i=0;i<SZ;i++) {
            for(lld j=0;j<SZ;j++) {
                res.MaGiC[i][j] = 0;
                for(lld k=0;k<SZ;k++) {
                    res.MaGiC[i][j] = add(res.MaGiC[i][j] , mult(MaGiC[i][k] , o.MaGiC[k][j]));
                }
            }
        }
        return res;
    }
};

matrix power(matrix a, lld b) {
    if (b == 0) {
        a.makeiden();
    }
    matrix res;
    res.makeiden();
    while(b) {
        if(b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}


// // GUIDE :
//
//  matrix m;
//  m.makeiden();
//
//  m.MaGiC[0][0] = 0, m.MaGiC[0][1] = 1;
//  m.MaGiC[1][0] = 3, m.MaGiC[1][1] = 2;
//
//  m = power(m, n);
//
//  cout << m.MaGiC[0][0];

		






void solveEachTest(int _TestCase) {
    // cout << "Case #" << _TestCase << ": ";
    lld n; cin >> n;

    matrix m;
    m.makeiden();

    m.MaGiC[0][0] = 0, m.MaGiC[0][1] = 1;
    m.MaGiC[1][0] = 3, m.MaGiC[1][1] = 2;

    m = power(m, n);

    cout << m.MaGiC[0][0];
    
    return;
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // cout.precision(10); cout << fixed;
    #ifdef LUCTIVUD
      // const auto start_time = std::chrono::high_resolution_clock::now();
      freopen("/home/luctivud/CPPractice/Zinput.txt", "r", stdin);
      freopen("/home/luctivud/CPPractice/Zoutput.txt", "w", stdout);
    #endif


    MOD = mod = lld(1e9) + 7ll;
    lld _T0T4 = 1;
    // cin >> _T0T4; 

    for (int _TestCase = 1; _TestCase <= _T0T4; _TestCase++) {
        solveEachTest(_TestCase);
        cout << "\n"; 
    }


    #ifdef LUCTIVUD
      // auto end_time = std::chrono::high_resolution_clock::now();
      // std::chrono::duration<double> diff = end_time - start_time;
      // cerr << "Finished in : " << diff.count() << "\n";
    #endif

    return 0; 
}


/*  ~~
Author   :  Udit "luctivud" Gupta 
linkedin :  https://www.linkedin.com/in/udit-gupta-1b7863135/
*/
