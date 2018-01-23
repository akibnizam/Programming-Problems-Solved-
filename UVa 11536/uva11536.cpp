#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <cmath>
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

int loo(int i, int x[], int *xin, int M) {
    if (i <= 3) return x[i - 1];

    int num = 0;
    FOR(j, 0, 3) num += x[j];
    num = num % M + 1;

    x[*xin] = num;
    *xin = ((*xin) + 1) % 3;
    return num;
}

int y[1000001];

int main() {

    int C;
    scanf("%d", &C);
    int T = C;
    while (T--) {
        int N, M, K;
        scanf("%d%d%d", &N, &M, &K);
        int start = 1;
        int count = 1;
        int vect[K + 1] = {0};
        vect[1] = 1;
        int arr[3] = {1, 2, 3};
        int ain = 0;


        int stt[3] = {1, 2, 3};
        int stin = 0;
        int min = 0;
        int realStart = 1;

        FOR(i, 1, N + 1) {
            int men;
            men = loo(i, arr, &ain, M);
            if (1 < i && men <= K) {
                vect[men] = vect[men] + 1;

                if (vect[men] == 1) count++;
                if (realStart == men) {
                    while (realStart > K || vect[realStart] > 1) {
                        if ( ! (realStart > K) ) vect[realStart] -= 1;
                        realStart = loo(++start, stt, &stin, M);
                    }
                }
            }

            int dd = (i - start) + 1;
            if (count == K) min = min == 0 || min > dd ? dd : min;
        }


        if (min == 0) printf("Case %d: sequence nai\n", C - T);
        else printf("Case %d: %d\n", C - T, min);
    }

    return 0;

}