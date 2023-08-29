/* main.cpp
 * cs10c_sum21
 * huffman 
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Huffman.h"

using namespace std;

int main(int argc, char* argv[]) {
  
  if (argc != 2) {
    cerr << "Usage error, expected: ./a.out *.txt\n";
    exit(1);
  }
  
  string input_file = argv[1];
  Huffman h(input_file);
  h.BuildHuffmanTree();
  h.PrintCharFrequencies();
  h.SetBitCodes();
  h.SetBitsPerChar();
  // h.Stats();
  h.BitMap();
  
  return 3;
}


