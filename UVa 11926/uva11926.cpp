#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>
#include <queue>
#include <new>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef unordered_map<int, int> mii;


#define FOR(n, x, count) for (int n = x; n < count; ++n)
#define ABS(n) ((n) < 0 ? -(n) : n)
#define M 1000000


#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))


void setInt(int *S, int i, int j) {
    i = i - 1;
    *S = *S | (~(1 << j) & (1 << i));
}



bool wek[M + 1];
int start, e, interval, n, m;
bool conflict;

bool checkCls() {
    FOR(i, start, e) {
        if (wek[i]) return false;
        wek[i] = true;
    }

    return true;
}

int main() {

    int n, m;
    while (true) {
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0) break;
        conflict = false;
        memset(wek, false, sizeof wek);
        //printf("%d\n", M + 1);
        while(n--) {
            scanf("%d%d", &start, &e);
            if (!checkCls() || conflict) conflict = true;
        }

        while(m--) {
            scanf("%d%d%d", &start, &e, &interval);
            while (start <= M && !conflict) {
                if (!checkCls() || conflict) conflict = true;
                start += interval;
                e = min(e + interval, M);
            }

        }

        if (conflict) printf("CONFLICT\n");
        else printf("NO CONFLICT\n");

    }

    return 0;

}