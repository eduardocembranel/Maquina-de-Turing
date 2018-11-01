#include "Fita.hpp"

Fita::Fita ()
{
   this->cadeia  = "*$";
   this->posFita = 1;
   this->atual   = 0;
}

void Fita::add (const std::string &cadeia)
{
   this->cadeia  = cadeia;
   this->posFita = 1;
   this->atual   = 0; 
}

void Fita::showFita () const
{
   std::cout << this->getFita();
}

std::string Fita::getFita () const
{
   std::string s = "";
   for (int i = 0; i < cadeia.size(); ++i)
   {
      if (i == posFita)
         s += "[q" + std::to_string(atual) + "]";
      s += cadeia[i];
   }
   return s + "\n";
}