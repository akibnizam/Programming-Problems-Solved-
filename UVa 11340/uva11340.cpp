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
    int N, K, little, total = 0;
    char c;
    unordered_map<char, int> map;
    vi v;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &K);
        FOR(i, K) {
            c = getchar();
            while (c == ' ' || c == '\n') c = getchar();
            scanf("%d", &little);
            map[c] = little;
        }

        scanf("%d", &K);
        getchar();
        while(K--) {
            string line = "";
            getline(cin, line);
            FOR(i, line.size()) {
                char c = line[i];
                if (c != ' ' && c != '\n' && map.find(c) != map.end()) {
                    total += map[c];
                }
            }
        }


        printf("%0.2f$\n", total/100.0);
        total = 0;
        map.clear();

    }

    return 0;

}