// hash.cpp associative C++ STL container experimentation
/*
template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = less<Key>,                     // map::key_compare
           class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
           > class map;

Dictionaries is the direct logical use for ordered maps, access time O(logN)
keys are references to the elements, which are *strictly ordered*, keys are
associated to a mapped value, identifying elements. Keys are unique. The allo-
cator object handles memory storage needs of the container dynamically.

A typedef pair<const Key, T> val_t binds the types of the key and the mapped
value and ordered maps must fit a strict weak ordering that has a definite
compare function, considering the "std::less" <functional>:
'98  template <class T> struct less : binary_function <T,T,bool> {
       bool operator() (const T& x, const T& y) const {return x<y;}
     };
'11
*..  template <class T> struct less {
       bool operator() (const T& x, const T& y) const {return x<y;}
       typedef T first_argument_type;
       typedef T second_argument_type;
       typedef bool result_type;
     };
A set-like assessment example is ```
// less example
#include <iostream>     // std::cout
#include <functional>   // std::less
#include <algorithm>    // std::sort, std::includes

int main () {
  int foo[]={10,20,5,15,25};
  int bar[]={15,10,20};
  std::sort (foo, foo+5, std::less<int>());  // 5 10 15 20 25
  std::sort (bar, bar+3, std::less<int>());  //   10 15 20
  if (std::includes (foo, foo+5, bar, bar+3, std::less<int>()))
    std::cout << "foo includes bar.\n";
  return 0;
}
``` trying with a C++14, -Wall -O2 [cpp.sh]
*/



#include <map>
#include <vector>
#include <functional>
#include <iostream>
using namespace std;

int main( )
{
  map<string, int> aa;
  aa["Adi"]=1986;
  aa["Bubu"]=1983;
  cout << "Nanmes and birthyears\n";
  for ( auto &e: aa ) {
    cout << e.first << "\t\t" << e.second << endl;
  }
  return 0;
}