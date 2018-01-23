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
typedef vector<vi> vvi;
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


    int n;

    int count = 0;
    int N[10010];
    int left[10010] = {-1};
    int head = -1;
    while (scanf("%d", &n) != EOF) {
        N[count++] = n;
        int med = count / 2;
        bool isEven = count % 2 == 0 ? true : false;

        if (head == -1 || N[head] > n) {
            left[count - 1] = head;
            head = count - 1;
        } else {
            int cur = head;
            while (N[left[cur]] < n) {
                cur = left[cur];
                if (left[cur] == -1) break;
            }

            left[count - 1] = left[cur];
            left[cur] = count - 1;
        }

        int cur = head;
        if (isEven) med = med - 1;
        FOR(i, med) cur = left[cur];

        int mm = isEven ? (N[cur] + N[left[cur]]) / 2 : N[cur];
        printf("%d\n", mm);
    }

    return 0;

}