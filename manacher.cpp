vector<int> manacher(string s) {
  string t = "#";
  for (auto c : s) {
    t += c;
    t += '#';
  }
  int n = t.size();
  vector<int> r(n);
  for (int i = 0, j = 0; i < n; i++) {
    if (2 * j - i >= 0 && j + r[j] > i) r[i] = min(r[2 * j - i], j + r[j] - i);
    while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]])
      r[i] += 1;
    if (i + r[i] > j + r[j]) j = i;
    r[i]--;
  }
  return vector<int>(begin(r) + 1, end(r) - 1);
}

// this is to check for palindrom length and whether a substring is a palindrome in O(n)
// to get longest length iterate and get max value
// to check for existent palindrome for range i j just check if the value at i+j index is greater than j-i+1;
// we can also get length from a center