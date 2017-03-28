string Solution::convertToTitle(int A) {
    string result;
    while (A) {
        result = char ((A - 1) % 26 + 'A') + result;
        A = (A - 1) / 26;
    }
    return result;
}
