#ifndef UTIL_HPP
#define UTIL_HPP

/*
* \file Util.hpp
* \class Util
* \brief Classe com metodos gerais e auxiliares
* \author Eduardo Cembranel 
* \author Guilherme Maci
* \author Lucas Rodrigues
* \author Ysyo Socorro
*/

#include <string>
#include <fstream>

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

      /* brief: ignora os caracteres de um arquivo txt ate um caracter
      * determinado ser lido
      * param: buffer de leitura de arquivo e caracter de parada
      * pre: arquivo aberto
      * pos: ter o cursor posicionado logo apos o caracter de parada
      */
      static void ignoraAte (std::ifstream &, char);


      /* brief: concatena um int e char separados por \n na forma de string 
      * param: inteiro e caracter a serem concatenados
      * return: string concatenada
      * pre: nenhuma
      * pos: ter retornado a string concatenada
      */
      static std::string concatena (int, char);
   
   private:
      /* brief: construtor privado, impossibilitando a instancia de objetos
      * pre: nenhuma
      * pos: nenhuma
      */
      Util ();
};

#endif // !UTIL_HPP