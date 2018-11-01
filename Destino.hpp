#ifndef DESTINO_HPP
#define DESTINO_HPP

#include <iostream>

class Destino
{
   friend class MaquinaTuring;

   private:
      enum Direcao {ESQUERDA = 0, DIREITA};

      int  estado;
      char saida;
      enum Direcao direcao;

      void teste () {
         std::cout << estado
                   << saida
                   << direcao;   
      }
};

#endif // !DESTINO_HPP