#ifndef ARGS_PARSER_H
#define ARGS_PARSER_H

struct Args {
  char *target;  // X
  char *replace; // Y
  char **paths;  // Z
  int pathsLen;
};

struct Args parseArgs(int argc, char *argv[]);

#endif
