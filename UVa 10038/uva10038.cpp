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




int main() {
    int bitvec = 1, n, a, b, dif;
    while(scanf("%d", &n) != EOF) {
        bitvec = 1 << n;
        bitvec -= 1;
        clearBit(bitvec, 0);
        scanf("%d", &a);
        for(int i = 0; i < n - 1; i++) {
            scanf("%d", &b);
            dif = ABS(b - a);
            if (dif < n) clearBit(bitvec, dif);
            //printf("%d\n", dif);
            a = b;
        }
        //printf("%d\n", bitvec);
        if (!bitvec)
        {
            printf("Jolly\n");
        } else {
            printf("Not Jolly\n");
        }
    }

    return 0;

}