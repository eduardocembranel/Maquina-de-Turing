#ifndef APP_HPP
#define APP_HPP

#include "maquinaTuring.hpp"

class App
{
   public:
      App ();
      void run ();
      ~App ();
   
   private:
      MaquinaTuring *maquina;
      void mostraMenu ();
      void carregaArquivo ();
      void processaCadeia ();

      enum Menu {CARREGA = 1, PROCESSA, SAIR};
};

#endif // !APP_HPP