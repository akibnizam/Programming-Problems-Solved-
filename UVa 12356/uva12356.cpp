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
#include <map>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unordered_map<int, int> mii;


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


    // The solution
    // https://saicheems.wordpress.com/2013/08/19/uva-12356-army-buddies/

    // Keep an array that stores who is left to a given soldier
    // Keep an array that stores who is right to a given soldier

    int S, B;
    int ls[100010];
    int rs[100010];
    scanf("%d %d", &S, &B);
    while (S != 0 || B != 0) {
        int L, R;
        FOR(i, S + 1) {
            ls[i] = i - 1;
            rs[i] = i + 1;
        }

        FOR(i, B) {
            scanf("%d %d", &L, &R);
            if (ls[L] < 1) printf("* ");
                else printf("%d ", ls[L]);
            if (rs[R] > S) printf("*\n");
                else printf("%d\n", rs[R]);

            ls[rs[R]] = ls[L];
            rs[ls[L]] = rs[R];
        }

        printf("-\n");

        scanf("%d %d", &S, &B);
    }

    return 0;


}