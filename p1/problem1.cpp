// Program to select from an array of integers
// all pairs of which the sum is within [A,B] or equals A.
// Build: from build subdir, run ba.cmd
// Usage: p1 A B or p1 A

// this version uses an external dataset in the "integers" file.

#include <iostream>     // for cout/cin
#include <fstream>      // for I/O from files
#include <cstdlib>      // for atoi
#include <vector>       // for dynamic array
#include <set>          // for set
#include <utility>      // for pair
#include <algorithm>    // for swap

int findPairsWithSumIn(int lower, int upper, std::vector<int>& v);

// =========================================================================
int main(int argc, char** argv)
{
    if ((argc == 1) || (argc > 3))
    {
        std::cout << "Wrong # args. (use p1 4 [5])" << std::endl;
    }
    else
    {
        int a, b;
        a = atoi( argv[1] );
        b = atoi( argv[std::min(argc-1,2)] );
        if (a > b) std::swap(a,b);
        std::cout << "Bounds: A = " << a << ", B = " << b << std::endl;

        // read the input file to integers
        std::ifstream ifile("integers");
        int i;
        std::vector<int> ai;
        std::cout << "Input: [ ";
        while (ifile >> i)
        {
            ai.push_back(i);
            std::cout << ai.back() << " ";
        }
        std::cout << "]." << std::endl;
        ifile.close();

        // now that the array of integers is in place, find pairs, that
        // add up to a number between the given bounds! :)
        std::cout << "Total number of pairs with sums in [A,B]: "
                  << findPairsWithSumIn(a, b, ai) << std::endl;
    }
    return 0;
}
// =========================================================================

int findPairsWithSumIn(int lower, int upper, std::vector<int>& v)
{
    int n = 0;  // number of matches for the condition

    // parse the array into an ordered set and show it
    std::set<int> si(v.begin(), v.end());
    std::cout << "The set reads: { ";
    for (auto i : si) std::cout << i << " ";
    std::cout << "}." << std::endl;

    std::cout << "Pairs in the set:" << std::endl;
    for (auto iti = si.begin(); iti != si.end(); ++iti)
    {
        for (auto itj = iti; ++itj != si.end(); /*pre-incremented itj*/)
        {
            std::cout << *iti << " + " << *itj;
            int sum = *iti + *itj;
            if ((sum >= lower) && (sum <= upper))
            {
                std::cout << "<- " << lower << "<=" << sum << "<=" << upper;
                n++;
            }
            std::cout << std::endl;
        }
    }
    return n;
}
