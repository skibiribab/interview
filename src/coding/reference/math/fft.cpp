// Complex FFT — polynomial multiplication over ℂ (round to nearest int)
// When: convolution when NTT modulus constraints don't fit; precision OK for small coeffs.
// Time: O(n log n)    Space: O(n)
#include <cassert>
#include <cmath>
#include <complex>
#include <vector>

using cd = std::complex<double>;
using std::vector;

static void fft(vector<cd>& a, bool invert) {
    const int n = (int)a.size();
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            std::swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * M_PI / len * (invert ? -1 : 1);
        cd wlen(std::cos(ang), std::sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; ++j) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (cd& x : a)
            x /= n;
}

static vector<long long> multiply(const vector<long long>& a, const vector<long long>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int)a.size() + (int)b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; ++i)
        fa[i] *= fb[i];
    fft(fa, true);
    vector<long long> res(n);
    for (int i = 0; i < n; ++i)
        res[i] = (long long)std::llround(fa[i].real());
    while (!res.empty() && res.back() == 0)
        res.pop_back();
    return res;
}

int main() {
    // (1+2x)(3+4x) = 3 + 10x + 8x²
    auto r = multiply({1, 2}, {3, 4});
    assert(r.size() >= 3);
    assert(r[0] == 3 && r[1] == 10 && r[2] == 8);
    return 0;
}
