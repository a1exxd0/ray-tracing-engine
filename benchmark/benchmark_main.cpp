#include <benchmark/benchmark.h>
#include "color3.h"

static void BM_Add_Colors(benchmark::State& state) {
    for (auto _ : state) {
        rte::color3 temp(1.0, 1.0, 1.0);
        rte::color3 result;

        for (int i = 0; i < 100000; i++) {
            result += temp;
        }
    }
    
}

BENCHMARK(BM_Add_Colors)
->Name("Add multiple colors together")
->Iterations(1000)
->MeasureProcessCPUTime();

BENCHMARK_MAIN();