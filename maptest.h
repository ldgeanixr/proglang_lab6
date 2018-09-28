#ifndef MAPTEST_INCLUDED
#define MAPTEST_INCLUDED   1

#include <map> 
#include <string> 
#include <fstream>
#include <iostream>

namespace maptest
{

}

std::ostream&
operator << ( std::ostream& stream,
const std::map< std::string, unsigned int > & freq );




#endif 