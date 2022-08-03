#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const i64 INF = 0x7fffffff;
const i64 MOD = 1000000007;
#define rep(i, a, b) for(int i=(a), __=(b); i<__; ++i)
#define per(i, a, b) for(int i=(b-1), __=(a); i>=__; --i)
i64 powmod(i64 a, i64 b) {i64 res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a;}

namespace IO    {
    template<typename T> inline T read()    {
        T x = 0, w = 1; char ch = getchar();
        while (!isdigit(ch)) {if (ch == '-')w *= -1; ch = getchar();}
        while (isdigit(ch)) { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
        return x * w;
    }
    template<typename T> inline void write(T x, char end_ch)    {
        if (x < 0) {x = -x; putchar('-');}
        static int sta[101]; int top = 0;
        do {sta[top++] = x % 10; x /= 10;} while (x);
        while (top) putchar(sta[--top] + 48);
        putchar(end_ch);
    }
}using namespace IO;
// #define _DEBUG
// #define _FILE_IO

i64 a[15],b[15];
bool flag[15];
i64 n, multi = 1, add = 0, ans = 0x7fffffff; // ans = INF
void dfs(i64 x) {
    if (x <= n) {
        rep(i, 1, n+1) 
			if(!flag[i]) {
				multi *= a[i];add += b[i];
                flag[i] = true;
				ans = min(ans, abs(multi-add));
				dfs(x+1);
				flag[i] = false;
				multi /= a[i];add -= b[i];
			}
    }
}

int main(int argc, char** argv)    {
#ifdef _FILE_IO
    freopen("data.in", "r", stdin);
    freopen("res.out", "w", stdout);
#endif
#ifdef _DEBUG
    
#endif
    memset(flag, false, sizeof(flag));
    n = read<i64>();
    rep(i, 1, n+1) a[i] = read<i64>(), b[i] = read<i64>();
    dfs(1);
    write<i64>(ans, '\n');

    return 0;
}
