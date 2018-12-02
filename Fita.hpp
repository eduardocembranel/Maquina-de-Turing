#ifndef FITA_HPP
#define FITA_HPP

/*
* \file Fita.hpp
* \class Fita
* \brief Classe que representa uma fita finita de uma maquina de turing
* \author Eduardo Cembranel 
* \author Guilherme Maci
* \author Lucas Rodrigues
* \author Ysyo Socorro
*/

#include <string>

class Fita
{
   protected:
      std::string cadeia; //cadeia de simbolos da fita
      int posFita; //posicao do simbolo atual da cadeia a ser processada
      int atual; //estado da maquina de turing atual
      
      /* brief: construtor que inicializa a fita com valores padroes
      * pre: nenhuma
      * pos: nenhuma
      */
      Fita (); 

      /* brief: adiciona uma nova fita
      * param: cadeia a ser adicionada para a fita
      * pre: nenhuma
      * pos: cadeia adicionada e posicao e estado da fita estabelecidos
      */
      void add(const std::string &);

      /* brief: exibe na tela a fita
      * pre: nenhuma
      * pos: ter os dados exibidos na tela
      */
      void showFita() const;

      /* brief: obtem os dados atuais da fita
      * return: string contendo as informacoes da fita
      * pre: nenhuma
      * pos: string retornada com as informacoes da fita
      */
      std::string getFita () const;
};

#endif // !FITA_HPP