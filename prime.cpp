static const int MAX_NUM = 10000;
bool prime[MAX_NUM];

void precomputePrimes() {
    fill(prime, prime + MAX_NUM, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i < MAX_NUM; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAX_NUM; j += i) {
                prime[j] = false;
            }
        }
    }
}