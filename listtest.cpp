
#include "listtest.h"

#include <random>
#include <chrono>
#include <algorithm>

void listtest::sort_move( std::list< std::string > & l )
{
   for( auto q = l. begin( ); q != l. end( ); ++ q )
        for( auto p = l. begin( ); p != q; ++ p )
        {
            if( *p > *q )
            {
                std::swap(*p,*q);
            }
}
}

void listtest::sort_assign( std::list< std::string > & l ){
   
   for( auto q = l. begin( ); q != l. end( ); ++ q )
        for( auto p = l. begin( ); p != q; ++ p )
        {
            if( *p > *q )
            {
                std::string s = *p;
                *p = *q;
                *q = s;
            }
         }
}

// They are not in the namespace,
// because uniqueness is guaranteed by their type.  WHAT DOES IT MEAN?
std::ostream& 
operator << ( std::ostream& out, const std::list< std::string > & lst){

   out << "{";

	for (auto p = lst.begin(); p != lst.end(); ++p )
	{
         if (p != lst.begin())
         {
            out << ", ";
         }

         out << "'"<<*p<<"'";



		// if (p == lst.begin())
  //     {
  //        out << "{ '"<< *p <<"'";
  //     }

  //     else if (p + 1 == lst.end())   // why p+1 here is not working for iterators on
  //     {
  //        out << ", '"<< *p <<"' }";
  //     }

  //     else
  //     {
  //        out << ", '"<< *p <<"'";
  //     }
	}

   out << "}\n";

   return out;
} 

std::list<std::string> listtest::vect_to_list (std::vector<std::string> &vect)
{
   std::list<std::string> l;
     
   for (size_t i = 0; i < vect.size(); ++i)
   {
      l.push_back(vect[i]);
   }

   return l;
}

