
#include <fstream>
#include <iostream>
#include <random>
#include <map>

#include "listtest.h"
#include "vectortest.h"
#include "timer.h"


std::map<std::string, unsigned int> frequencytable
(const std::vector<std::string> & text)
{
  std::map<std::string, unsigned int> freq;

  for (const auto& s:text)
  {
    freq[s]++;
  }

  return freq;
}

std::ostream&
operator << ( std::ostream& stream,
const std::map< std::string, unsigned int > & freq )
{
  for( const auto& p : freq )
  {
    stream << p. first << " => " << p. second << "\n";
  }

  return stream;
}


int main( int argc, char* argv [] )
{

  std::vector<std::string> vect = {"A", "A", "A", "B", "C"};
  std::cout << frequencytable(vect) << "\n\n\n";
  std::cout << frequencytable( std::vector< std::string >
{ "AA", "aA", "Aa", "this", "THIS" } );




  return 0;
}



