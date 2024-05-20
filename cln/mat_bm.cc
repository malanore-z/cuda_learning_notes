//
// Created by malanore on 24-5-21.
//

#include "cln/mat.h"

#include <benchmark/benchmark.h>

static void BM_FloatAdd(benchmark::State& state) {
    for (auto _: state) {
        float res = FloatAdd(1.1, 2.2);
    }
}
BENCHMARK(BM_FloatAdd);

BENCHMARK_MAIN();
