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


    int sz, p;
    while (scanf("%d%d", &sz, &p), p && sz) {
        int n = 1, s = 1;
        bool line = true;
        bool col = false;
        int x = (sz / 2) + 1;
        int y = x;
        bool subv = true;
        while ((n + s) < p) {
            n += s;
            if (subv)
            {
                if (line) x += s;
                    else x -= s;
                line = !line;
            } else {
                if (col) y += s;
                    else y -= s;
                col = !col;
            }

            subv = !subv;
            if (subv) s++;
        }

        while (n != p) {
            n++;
            if (subv)
            {
                if (line) x += 1;
                    else  x -= 1;
            } else {
                if (col)  y += 1;
                    else  y -= 1;
            }
        }

        printf("Line = %d, column = %d.\n", x, y);
    }

    return 0;

}