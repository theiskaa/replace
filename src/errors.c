#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *helpText =
    "Usage: rp {x} {y} ... {z}\n\n"
    "The 'rp' command is a versatile tool for efficiently replacing content "
    "within specified files.\n\n"
    "Arguments:\n"
    " (X)SOURCE        Specify the source content to be replaced\n"
    " (Y)TARGET        Specify the target content to replace the source\n"
    " (Z)FILES         Specify the target files or folders where replacement "
    "will be applied\n\n"
    "Examples:\n"
    "  rp \"color\" \"colour\" \"folder_name/*.md\"\n"
    "     Replace all occurrences of \"color\" with \"colour\" in Markdown "
    "files within 'folder_name'.\n"
    "  rp \"old_text\" \"new_text\" \"file.txt\"\n"
    "     Replace \"old_text\" with \"new_text\" in 'file.txt'.\n"
    "  rp \"typo\" \"correction\" \"*.txt\"\n"
    "     Replace \"typo\" with \"correction\" in all text files in the "
    "current directory.\n\n"
    "Notes:\n"
    "- You can use shell wildcards (*, ?) for file/folder selection.\n"
    "- If no 'FILES' argument is provided, the operation will be applied to "
    "all matching values under the current folder.\n";

void printHelp() { printf("%s\n", helpText); }

void checkArgs(int argc, char *argv[]) {
  if (argc < 2) {
    printHelp();
    exit(1);
    return;
  }

  if (argc < 3) {
    if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "-h") == 0 ||
        strcmp(argv[1], "--help") == 0) {
      printHelp();
      exit(1);
      return;
    }
    fprintf(stderr, "Error: target(X) is provided but replace(Y) is not");
    exit(1);
  }
}
