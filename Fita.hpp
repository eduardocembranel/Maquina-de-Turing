#ifndef FITA_HPP
#define FITA_HPP

#include <string>
#include <iostream>

class Fita
{
   protected:
      std::string cadeia;
      int posFita;
      int atual;
      
      Fita (); 
      void add(const std::string &);
      void showFita() const;
      std::string getFita () const;
};

#endif // !FITA_HPP