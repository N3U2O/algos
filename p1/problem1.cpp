// program to select from an array of integers
// all pairs of which the sum is between A and B

// Usage: p1 A B i1 i2 i3 ..., also a good idea to use
// as p1 A B < integers <-- this is stdin!!
// or rather p1 < integers => whole file is read from stdin
// with the bash [$ p1 "$(< integers)"] feature the file
// contents can contain the args.

// this version uses a fixed dataset in the "integers" file.

#include <iostream>     // for cout/cin
#include <fstream>      // for I/O from files
#include <cstdlib>      // for atoi
#include <vector>       // for dynamic array
#include <utility>      // for pair
#include <algorithm>    // for swap

const int niMax = 100;

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cout << "Wrong # args. (use p1 40 50)" << std::endl;
    }
    else
    {
        int a, b;
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        if (a > b) std::swap(a,b);
        std::cout << "Bounds: A = " << a << ", B = " << b << std::endl;

        // read the input file to integers
        std::ifstream ifile("integers");
        int i;
        std::vector<int> ai;
        while (ifile >> i)
        {
            ai.push_back(i);
            std::cout << ai.back() << " ";
        }
    }
    return 0;
}
