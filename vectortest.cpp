
#include "vectortest.h"

#include <random>
#include <chrono> 
#include <algorithm>

std::vector< std::string >
vectortest::randomstrings( size_t nr, size_t s )
{
   static std::default_random_engine gen( 
      std::chrono::system_clock::now( ). time_since_epoch( ). count( ) );
         // Narrowing long int into int, but that is no problem.

   static std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345689";
   static std::uniform_int_distribution<int> distr( 0, alphabet. size( ) - 1 );
      // More narrowing.

   std::vector< std::string > res;

   for( size_t i = 0; i < nr; ++ i )
   {
      std::string rand;
      for( size_t j = 0; j < s; ++ j )
      {
         rand. push_back( alphabet[ distr( gen ) ] );  
      }

      res. push_back( std::move( rand ));
   }
   return res;
}
         

//#if 1 // change it to 0 
std::vector<std::string> 
vectortest::readfile( std::istream& input ) 
{
   std::vector<std::string> vect;
   
   
   std::string str = "";
   

   while (!input.eof())
   {
      char c = input.get();

      if (isalpha(c) != 0)
      {
         str+=c;
      }

      else
      {
         if (str.length()!=0)
         {
             vect.push_back(str);
             str = "";
         }
      }
   }

   return vect;
}


std::ostream& 
operator << ( std::ostream& out, const std::vector< std::string > & vect ) 
{ 
   for (auto p = vect.begin(); p!=vect.end(); ++p) // where vect.begin is pointing?
   {
      

      if (p == vect.begin())
      {
         out << "{ '"<< *p <<"'";
      }

      else if (p + 1 == vect.end())   // where vect.end is pointing???
      {
         out << ", '"<< *p <<"' }\n";
      }

      else
      {
         out << ", '"<< *p <<"'";
      }
   }

   return out;
}

void vectortest::sort_assign( std::vector< std::string > & v )
{
   for( size_t j = 0; j < v. size( ); ++ j )

      for( size_t i = 0; i < j; ++ i )
      {
         if( v[i] > v[j] )
         {
             std::string s = v[i];
             v[i] = v[j];
             v[j] = s;             
         }
      }
}

void vectortest::sort_move( std::vector< std::string > & v )
{
   for( size_t j = 0; j < v. size( ); ++ j )
   {
      for( size_t i = 0; i < j; ++ i )
      {
         if( v[i] > v[j] )
         std::swap( v[i], v[j] );
      }
   }
}

void vectortest::sort_std( std::vector< std::string > & v )
{
std::sort( v. begin( ), v. end( ));
}




