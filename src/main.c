#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // TODO: import help
  if (argc < 3) {
    printf("Usage: rp {X} {Y} ... {Z}\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
