#include "dpf.h"
#include "hashdatastore.h"

#include <assert.h>
#include <chrono>
#include <iostream>


std::array<uint8_t,32> testBlock() {
  std::array<uint8_t, 32> ret;
  for (int i = 0; i < 32; i++) {
    ret[i] = (uint8_t)i;
  }

  return ret;
}

int testEvalFull8(size_t N, int alpha)  {
    auto beta = testBlock();
    auto keys = DPF::Gen(alpha, N, beta);
    auto a = keys.first;
    auto b = keys.second;
    std::vector<uint8_t> aaaa = DPF::EvalFull8(a, N);
    std::vector<uint8_t> bbbb = DPF::EvalFull8(b, N);

    for (size_t i=0; i<aaaa.size(); i++) {
      uint8_t res = aaaa[i] ^ bbbb[i];
      if(i/32 == (size_t)alpha) {
        assert(res == beta[i%32]);
      } else {
        assert(res == 0);
      }
    }
    return 0;
}

int main(int argc, char** argv) {
    int res = 0;
    res = testEvalFull8(9, 123);
    res = testEvalFull8(15, 0);
    res = testEvalFull8(15, 8);
    res = testEvalFull8(15, 73);
    res = testEvalFull8(20, 730);
    return res;
}
