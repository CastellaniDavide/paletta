#include <bits/stdc++.h>
using namespace std;


long long int singolo(vector<long long int> input) {
    long long int solution = 0;
    /*map <int, pair <int, int> > tmp;

    for (size_t i = 0; i < input.size(); ++i) {
        map<int, pair <int, int> >::iterator t = upper_bound(tmp.begin(), tmp.end(), input[i]);
        if (t == tmp.end()) {
        } else {
            solution += 
            tmp[(t - tmp.begin())].second += 1;
        }
            tmp[input[i]] = make_pair(i, 0);
    }*/

    for (size_t i = 0; i < input.size(); ++i) {
        long long int tmp = 0;
        for (size_t j = i; j < input.size(); j++)
            if(input[i] > input[j])
                tmp--;

        solution -= tmp;
    }

    return solution;
}

long long paletta_sort(int N, int V[]) {
    // Local variabiles
    vector <long long int> pari((int) (N + 1)/2);
    vector <long long int> dispari((int) N/2);

    for (size_t i = 0; i < N; ++i) {
        if (i%2 != V[i]%2)
            return -1;

        if(i%2 == 0) {
            pari[(int) i/2] = V[i] / 2;
        } else {
            dispari[(int) i/2] = V[i] / 2;
        }
    }

    return singolo(pari) + singolo(dispari);
}

