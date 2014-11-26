// program to select from an array of integers
// all pairs of which the sum is between A and B

// Usage: p1 A B i1 i2 i3 ..., also a good idea to use
// as p1 A B < integers <-- this is stdin!!
// or rather p1 < integers => whole file is read from stdin
// with the bash [$ p1 "$(< integers)"] feature the file
// contents can contain the args.

// this version uses a fixed dataset in the "integers" file.

#include <iostream>
#include <cstdlib>
#include <utility>
#include <algorithm>

const int niMax = 100;

int main(int argc, char** argv)
{
    if (argc != 3) std::cout << "Wrong # args." << std::endl;
    int a, b;
    // try
    // {
    //     a = atoi(argv[1]);
    //     b = atoi(argv[2]);
    // }
    // catch (int exc)
    // {
    //     std::cout << "Wrong input format.\n"
    //                  "Exception code: " << exc << std::endl;
    // }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    if (a > b) std::swap(a,b);
    std::cout << "A = " << a << ", B = " << b << std::endl;

    std::ifstream ifile("integers");
    int i = 0;
    i << ifile.read();
    std::cout << i;
    return 0;
}
