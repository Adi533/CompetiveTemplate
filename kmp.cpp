vector<int> kmp(string s) {
    vector<int> lps(s.size(), 0);
    for (int i = 1; i < lps.size(); i++) {
        int prev_idx = lps[i - 1];
        while (prev_idx > 0 && s[i] != s[prev_idx]) {
            prev_idx = lps[prev_idx - 1];
        }
        lps[i] = prev_idx + (s[i] == s[prev_idx] ? 1 : 0);
    }
    return lps;
}
bool isSubstring(string needle, string haystack) {
    string combined = needle + "#" + haystack;
    vector<int> lps = kmp(combined);
    for (int i = needle.size() + 1; i < lps.size(); i++) {
        if (lps[i] == needle.size()) {
            return true;
        }
    }
    return false;
}