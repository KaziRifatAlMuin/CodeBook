#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAXN = 1000000;

vector<vector<pair<int, int>>> sieve_prime_factors_with_counts(int max_n) {
    vector<int> spf(max_n + 1);  // Smallest prime factor for each number
    vector<vector<pair<int, int>>> prime_factors(max_n + 1);

    // Initialize spf array
    for (int i = 2; i <= max_n; ++i) {
        spf[i] = i;
    }

    // Modified Sieve of Eratosthenes to populate spf
    for (int i = 2; i * i <= max_n; ++i) {
        if (spf[i] == i) {  // i is a prime number
            for (int j = i * i; j <= max_n; j += i) {
                if (spf[j] == j) {  // j has not been marked yet
                    spf[j] = i;
                }
            }
        }
    }

    // Factorization and count the prime factors for each number
    for (int i = 2; i <= max_n; ++i) {
        int num = i;
        while (num != 1) {
            int prime = spf[num];
            int count = 0;
            while (spf[num] == prime) {
                num /= prime;
                count++;
            }
            prime_factors[i].emplace_back(prime, count);
        }
    }

    return prime_factors;
}

int main() {
    int max_n = MAXN;
    vector<vector<pair<int, int>>> result = sieve_prime_factors_with_counts(max_n);
    
    // Example: Printing prime factors and their counts for the number 100
    int number;
    cin >> number;
    cout << "Prime factors and their counts for " << number << ":" << endl;
    for (auto& factor : result[number]) {
        cout << factor.first << "^" << factor.second << " ";
    }
    cout << endl;

    return 0;
}