#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>
#include <vector>
#include <fstream>

/*
* \file Util.hpp
* \class Util
* \brief Classe totalmente privada, com metodos gerais e auxiliares
* \author Eduardo Cembranel 
* \author Guilherme Maci
* \author Lucas Rodrigues
* \author Ysyo Socorro
*/

class Util
{
   public:
      /* brief: limpa a tela do console
      * pre: nenhuma
      * pos: tela limpada do console
      */
      static void clear ();

      /* brief: exibe a mensagem esperando por um ENTER e aguarda o mesmo
      * pre: buffer de entrada esta limpo
      * pos: nenhuma
      */
      static void pressRetornar();

      /* brief: limpa os dados de entrada, para tirar espaços desnescessários
      * pre: nenhuma
      * pos:ter retirado os espaços desnecessários
      */
      static void flushInput ();

      static void ignoraAte (std::ifstream &, char);
      
      static std::string concatena (int, char);
   
   private:
      /* brief: construtor privado, impossibilitando a instancia de objetos
      * pre: nenhuma
      * pos: nenhuma
      */
      Util ();
};

#endif // !UTIL_HPP