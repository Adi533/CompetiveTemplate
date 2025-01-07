const ll RADIX_1 = 26;
const ll MOD_1 = 1000000007;
const ll RADIX_2 = 27;
const ll MOD_2 = 1000000033;
pair<ll, ll> hashPair(string str, ll m) {
    ll hash1 = 0, hash2 = 0;
    ll factor1 = 1, factor2 = 1;
    for (ll i = m - 1; i >= 0; i--) {
        hash1 += ((str[i] - 'a') * factor1) % MOD_1;
        factor1 = (factor1 * RADIX_1) % MOD_1;
        hash2 += ((str[i] - 'a') * factor2) % MOD_2;
        factor2 = (factor2 * RADIX_2) % MOD_2;
    }
    return {hash1 % MOD_1, hash2 % MOD_2};
}
bool rabinKarpSearch(string haystack, string needle) {
    ll n = haystack.length(), m = needle.length();
    if (n < m) return false;
    ll MAX_WEIGHT_1 = 1, MAX_WEIGHT_2 = 1;
    for (ll i = 0; i < m; i++) {
        MAX_WEIGHT_1 = (MAX_WEIGHT_1 * RADIX_1) % MOD_1;
        MAX_WEIGHT_2 = (MAX_WEIGHT_2 * RADIX_2) % MOD_2;
    }
    pair<ll, ll> hashNeedle = hashPair(needle, m);
    pair<ll, ll> hashHay = {0, 0};
    for (ll i = 0; i <= n - m; i++) {
        if (i == 0) {
            hashHay = hashPair(haystack, m);
        } else {
            hashHay.first = ((hashHay.first * RADIX_1) % MOD_1
                    - ((haystack[i - 1] - 'a') * MAX_WEIGHT_1) % MOD_1
                    + (haystack[i + m - 1] - 'a') + MOD_1) % MOD_1;
            hashHay.second = ((hashHay.second * RADIX_2) % MOD_2
                    - ((haystack[i - 1] - 'a') * MAX_WEIGHT_2) % MOD_2
                    + (haystack[i + m - 1] - 'a') + MOD_2) % MOD_2;
        }
        if (hashNeedle.first == hashHay.first && hashNeedle.second == hashHay.second) {
            return true;
        }
    }
    return false;
}