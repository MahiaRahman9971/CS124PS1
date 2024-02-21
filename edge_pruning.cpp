#include <iostream>
#include <vector>
#include <random>
#include <cmath>
using namespace std;

// function for determining threshold 
// input: number of nodes, dimensions
// output: threshold
float threshold(int n, int d) {
    if (d == 2) {
        return 0.58628519 * exp(-0.02367409 * n) + 1.08047579;
    }
    else if (d == 3) {
        return 0.4363 * exp(-0.01144 * n) + 1.1719;
    }
    else if (d == 4) {
        return 0.58212611 * exp(-0.01570833 * n) + 1.28547444;
    }
    else return 0;
}