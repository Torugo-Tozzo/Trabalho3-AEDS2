#ifndef NO_H_
#define NO_H_
#include <string>
#include "lista.h"

class No {
 public:
  Veiculo *veiculo;
  No *left;
  No *right;
  int h;

  No(Veiculo *v) {
    veiculo = v;
    left = NULL;
    right = NULL;
    h = 1;
  }
};

#endif