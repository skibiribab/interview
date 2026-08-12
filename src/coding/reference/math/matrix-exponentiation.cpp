// Matrix exponentiation — linear recurrences (Fibonacci) via 2×2 (or k×k) pow
// When: F(n) mod M, linear DP with fixed transition; O(k³ log n).
// Time: O(k³ log n)    Space: O(k²)
#include <cassert>
#include <vector>

using std::vector;

using Matrix = vector<vector<long long>>;

static Matrix mat_mul(const Matrix& A, const Matrix& B, long long mod) {
    int n = (int)A.size();
    Matrix C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            if (!A[i][k])
                continue;
            for (int j = 0; j < n; ++j)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
        }
    }
    return C;
}

static Matrix mat_pow(Matrix base, long long exp, long long mod) {
    int n = (int)base.size();
    Matrix res(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i)
        res[i][i] = 1;
    while (exp) {
        if (exp & 1)
            res = mat_mul(res, base, mod);
        base = mat_mul(base, base, mod);
        exp >>= 1;
    }
    return res;
}

static long long fibonacci_nth(long long n, long long mod) {
    if (n == 0)
        return 0;
    Matrix T = {{1, 1}, {1, 0}};
    Matrix P = mat_pow(T, n - 1, mod);
    return P[0][0];
}

int main() {
    assert(fibonacci_nth(10, 1000000007) == 55);
    assert(fibonacci_nth(1, 1000000007) == 1);
    return 0;
}
