#include <stdio.h>
#include <stdlib.h>

// Logs appropriate help/error message and returns main execution value.
int checkArgs(int argc) {
  if (argc < 2) {
    fprintf(stderr, "Usage: rp {X} {Y} ... {Z}\n");
    return EXIT_FAILURE;
  } else if (argc < 3) {
    fprintf(stderr, "Error: target(X) is provided but replace(Y) is not");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
