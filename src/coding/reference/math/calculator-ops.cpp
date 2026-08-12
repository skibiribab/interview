// Foundation calculator ops — int64 add/sub/mul/div with assert-based unit tests.
#include <cassert>
#include <cstdint>
#include <optional>
#include <utility>

static int64_t arith_add(int64_t a, int64_t b) { return a + b; }

static int64_t arith_subtract(int64_t a, int64_t b) { return a - b; }

static int64_t arith_multiply(int64_t a, int64_t b) { return a * b; }

static std::optional<int64_t> arith_divide(int64_t a, int64_t b) {
    if (b == 0) {
        return std::nullopt;
    }
    return a / b;
}

int main() {
    assert(arith_add(14, 5) == 19);
    assert(arith_add(0, 0) == 0);
    assert(arith_subtract(20, 6) == 14);
    assert(arith_multiply(7, 8) == 56);
    assert(arith_divide(45, 9) == 5);
    assert(arith_divide(-20, 4) == -5);
    assert(!arith_divide(1, 0).has_value());
    return 0;
}
