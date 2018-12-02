#ifndef DESTINO_HPP
#define DESTINO_HPP

/*
* \file Destino.hpp
* \class Destino
* \brief Classe que representa a entidade Destino de uma transicao da maquina
* de turing. EX: (q1, a) -> q0, X, D. Neste caso (q0, X, D) seria o destino
* \author Eduardo Cembranel
* \author Guilherme Maci
* \author Lucas Rodrigues
* \author Ysyo Socorro
*/

class Destino
{
   friend class MaquinaTuring;

   private:
      int  estado; //estado de destino
      char saida; //simbolo que ira substituir o atual
      char direcao; //direcao de movimento para a fita
};

#endif // !DESTINO_HPP