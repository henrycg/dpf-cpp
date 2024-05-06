#pragma once

#include <cstdlib>
#include <vector>

#include "Defines.h"
namespace DPF {
    std::pair<std::vector<uint8_t>, std::vector<uint8_t> > Gen(size_t alpha, size_t logn, const std::array<uint8_t,32>& beta);
    std::vector<uint8_t> EvalFull8(const std::vector<uint8_t>& key, size_t logn);
}

extern "C" {
void GoGen(uint8_t *keyA, uint8_t *keyB, size_t* len,  size_t alpha, size_t logn, uint8_t *beta_in);
void GoEval(uint8_t *out, uint8_t *keyA, size_t logn);
}
