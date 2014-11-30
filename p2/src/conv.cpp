// conv.cpp -- Program to convolve two vectors
// Input is read from input.dat
//
// Build: From build subdir, run ba.cmd or ba.sh
//        At the shell to compile and rerun (with time info):
//
//        $ ./ba.sh && cd bin && time ./conv.exe $1 && cd ..
//
// It is a good idea for testing to create an alias for the line above.

#include <iostream>     // for cout/cin
#include <string>       // for strings
#include <fstream>      // for file I/O
#include <sstream>      // for stringstreams
#include <vector>       // for dynamic array
#include <iterator>     // for ostream_iterator
#include <cstdlib>      // for atof





// =========================================================================
// FUNCTION PROTOTYPES
// -------------------------------------------------------------------------
// read a string into a vector of doubles
void readVecd( std::vector<double>& vx, const std::string& line );
// display the vector separated by commas
void printVecd( const std::vector<double>& vx );
// convolve two vectors
std::vector<double> conv( const std::vector<double>& vx,
                          const std::vector<double>& vy  );
// -------------------------------------------------------------------------
// TESTS
// -------------------------------------------------------------------------
// test the convolution
void testConv( const std::vector<double>& vz,
               const std::vector<double>& vzref );
// test the I/O
void testReadAndPrint(std::ifstream& ifile);
// =========================================================================






// =========================================================================
// ***   MAIN   ***
// -------------------------------------------------------------------------
int main(int argc, char** argv)
{
    // The vectors to convolve and the output vector
    std::vector<double> vx, vy, vz, vzref;
    std::string ifileName = "input.dat";
    if (argc == 2) ifileName = argv[1];
    std::ifstream ifile(ifileName);
    if (ifile.is_open())
    {
        // testReadAndPrint(ifile);
        std::string line;

        // read first vector
        std::getline(ifile, line);
        readVecd(vx, line);

        // read second vector
        std::getline(ifile, line);
        readVecd(vy, line);

        // read ref. result vector
        std::getline(ifile, line);
        readVecd(vzref, line);
        ifile.close();

        // perform the convolution
        vz = conv(vx, vy);

        // print the results
        printVecd(vx);
        std::cout << "convolved by\n";
        printVecd(vy);
        std::cout << "is\n";
        printVecd(vz);

        // test the results
        std::cout << "\nTesting..." << std::endl;
        testConv(/*vx, vy,*/ vz, vzref);
    }
    else
    {
        std::cout << "Can't open file!";
    }

    return 0;
}
// =========================================================================






// =========================================================================
// FUNCTION IMPLEMENTATIONS
// -------------------------------------------------------------------------
void readVecd(std::vector<double>& vx, const std::string& line)
{
    vx.clear();
    std::istringstream iss(line);
    std::vector<std::string> snums;
    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              std::back_inserter(snums));
    for (auto snum : snums)
    {
        double x = atof(snum.c_str());
        vx.push_back(x);
    }    
}
// -------------------------------------------------------------------------
void printVecd(const std::vector<double>& vx)
{
    std::ostringstream ss;
    std::copy( vx.begin(),
               vx.end() - 1,
               std::ostream_iterator<double>(ss, ", ") );
    ss << vx.back();
    std::cout << ss.str() << std::endl;
}
// -------------------------------------------------------------------------
std::vector<double> conv( const std::vector<double>& vx,
                          const std::vector<double>& vy  )
{
    std::vector<double> vz;
    for (int n = 0; n < vx.size() + vy.size() - 1; ++n)
    {
        double s = 0;
        for (int i = 0; i < vx.size(); i++)
            for (int j = 0; j < vy.size(); j++)
                if (i + j == n) s += vx[i] * vy[j];
        vz.push_back(s);
    }
    return vz;
}
// -------------------------------------------------------------------------
// TEST IMPLEMENTATIONS
// -------------------------------------------------------------------------
void testConv( const std::vector<double>& vz,
               const std::vector<double>& vzref )
{
    int Nref = vzref.size();
    for (int i = 0; i <= Nref; ++i)
    {
        if (vzref[i] == vz[i]) std::cout << "coeff " << Nref-i-1 << " OK.\n";
    }
}
// -------------------------------------------------------------------------
void testReadAndPrint(std::ifstream& ifile)
{
    std::string line;
    while (std::getline(ifile, line))
    {
        if (line[0] == ';') continue;
        std::vector<double> vx;
        readVecd(vx, line);
        printVecd(vx);
    }
}
// =========================================================================
