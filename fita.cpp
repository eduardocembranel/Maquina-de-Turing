#include <iostream>

#include "Fita.hpp"

/* brief: construtor que inicializa a fita com valores padroes
* pre: nenhuma
* pos: nenhuma
*/
Fita::Fita ()
{
   this->cadeia  = "*$";
   this->posFita = 1;
   this->atual   = 0;
}

/* brief: adiciona uma nova fita
* param: cadeia a ser adicionada para a fita
* pre: nenhuma
* pos: cadeia adicionada e posicao e estado da fita estabelecidos
*/
void Fita::add (const std::string &cadeia)
{
   this->cadeia  = "*" + cadeia + "$";
   this->posFita = 1;
   this->atual   = 0;
}

/* brief: exibe na tela a fita
* pre: nenhuma
* pos: ter os dados exibidos na tela
*/
void Fita::showFita () const
{
   std::cout << this->getFita();
}

/* brief: obtem os dados atuais da fita
* return: string contendo as informacoes da fita
* pre: nenhuma
* pos: string retornada com as informacoes da fita
*/
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