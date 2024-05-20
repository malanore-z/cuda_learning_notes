
#include <spdlog/spdlog.h>

#include "cln/mat.h"

int main() {
    spdlog::info("1.1 + 2.2 = {}", FloatAdd(1.1, 2.2));
    return 0;
}
