#include "Interpreter/Interpreter.hpp"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cerr << "Please provide an input file.\n";
    return 1;
  }

  ifstream input(argv[1]);
  if (input.bad()) {
    cerr << "Cannot open input file.\n";
    return 1;
  }

  Interpreter interpreter(input);
  interpreter.write(cout);
  return 0;
}
