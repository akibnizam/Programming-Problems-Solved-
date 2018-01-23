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


void looper(vi *st, int *time, queue<int> *temp, int Q, int S, int i) {
    while (st->size() > 0) {
        (*time)++;
        if ((*st)[st->size() - 1] == i) st->pop_back();
            else if (temp->size() < Q && st->size() > 0) {
                temp->push((*st)[st->size() - 1]);
                st->pop_back();
            }
            else {
                (*time)--;
                break;
            }
    }

    while (st->size() < S && temp->size() > 0) {
        (*time)++;
        int tt = temp->front();
        st->push_back(tt);
        temp->pop();
    }
}

int main() {

    int sets;
    scanf("%d", &sets);
    while (sets--) {
        int N, S, Q;
        scanf("%d%d%d", &N, &S, &Q);
        vi st;
        vector<queue<int>> qs;
        int time = 0;
        queue<int> o;
        qs.push_back(o);

        FOR(i, 1, N + 1) {
            if (i > 1) time += 2;
            int inQ;
            queue<int> temp;

            scanf("%d", &inQ);

            FOR(j, 0, inQ) {
                int num;
                scanf("%d", &num);
                temp.push(num);
            }

            looper(&st, &time, &temp, Q, S, i);

            qs.push_back(temp);

        }

        // printf("%d\n", 2 % 5);
        for (int i = 1; st.size() > 0; i++)
        {
            time += 2;
            i = i % (N + 1) > 0 ? i : 1;
            looper(&st, &time, &(qs[i]), Q, S, i);
        }

        printf("%d\n", time);
    }

    return 0;

}