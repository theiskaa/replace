#include <stdio.h>
#include <stdlib.h>

void checkArgs(int argc) {
  if (argc < 2) {
    fprintf(stderr, "Usage: rp {X} {Y} ... {Z}\n");
    exit(1);
  } else if (argc < 3) {
    fprintf(stderr, "Error: target(X) is provided but replace(Y) is not");
    exit(1);
  }
}
