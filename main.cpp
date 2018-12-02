#include "App.hpp" 

/* brief: funcao principal que inicializa o programa
* pre: nenhuma
* pos: nenhuma
* return: flag para SO - 0: sucesso 1: erro
*/
int main (int argc, char **argv)
{
   App *app = new App(argc, argv);
   app->run();
   
   delete app;
   return 0;
}