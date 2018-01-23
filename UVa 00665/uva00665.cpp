#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <cmath>
#include <cstdio>
#include <stack>
#include <new>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


#define FOR(n, count) for (int n = 0; n < count; ++n)


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




int main() {
    int M;
    scanf("%d", &M);
    //printf("asdad\n");
    //scanf("");
    vi false_c;
    while (M--) {


        scanf("\n");
        scanf("\n");

        int N, K;
        scanf("%d %d", &N, &K);
        bool coins[N + 1] = {false};
        while (K--) {
            int half;
            scanf("%d ", &half);
            int *firs = new int[half];
            int *sec = new int[half];
            FOR(i, half) {
                scanf("%d", &firs[i]);
            }

            FOR(i, half) {
                scanf("%d", &sec[i]);
            }

            scanf("\n");
            char c;
            scanf("%c", &c);
            if (c == '=')
            {
                FOR(i, half) {
                    coins[firs[i]] = true;
                }

                FOR(i, half) {
                    coins[sec[i]] = true;
                }
            }
        }

        bool prr = false;

        for (int i = 1; i < N + 1; ++i) {
            if (!coins[i])
            {
                if (prr)
                {
                    false_c.pop_back();
                    prr = false;
                    break;
                }
                false_c.push_back(i);
                prr = true;
            }

        }

        if (!prr)
        {
            false_c.push_back(0);
        }

    }

    FOR(i, false_c.size()) {
        printf("%d\n", false_c[i]);
        if (i < false_c.size() - 1) printf("\n");
    }
    //printf("\n");
}