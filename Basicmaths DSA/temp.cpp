#include <iostream>
#include <vector>
#include<cmath>

void segmentedSieve(int L, int R) {
    int limit = sqrt(R);
    std::vector<bool> isPrime(limit + 1, true);

    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }

    std::vector<bool> segment(R - L + 1, true);
    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            int start = std::max(p * p, (L + p - 1) / p * p);
            for (int i = start; i <= R; i += p) {
                segment[i - L] = false;
            }
        }
    }

    for (int i = 0; i <= R - L; i++) {
        if (segment[i]) {
            std::cout << i + L << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int L, R;
    std::cout << "Enter the range [L, R]: ";
    std::cin >> L >> R;

    segmentedSieve(L, R);

    return 0;
}
