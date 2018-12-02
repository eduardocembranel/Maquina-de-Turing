#ifndef APP_HPP
#define APP_HPP

/*
* \file App.hpp
* \class App
* \brief Classe responsavel por gerenciar as funcionalidades do programa
* \author Eduardo Cembranel 
* \author Guilherme Maci
* \author Lucas Rodrigues
* \author Ysyo Socorro
*/

#include "MaquinaTuring.hpp"

class App
{
   public:
      /* brief: construtor que aloca e inicializa a maquina de turing
      * argumentos passados pela linha de comando
      * pre: nenhuma
      * pos: variavel alocada
      */ 
      App (int, char **);

      /* brief: metodo responsavel por iniciar e executar o programa
      * pre: nenhuma
      * pos: nenhuma
      */ 
      void run ();

      /* brief: Destrutor da classe: desaloca o espaco de maquina de turing
      * pre: maquina de turing alocada
      * pos: variavel desalocada da memoria
      */ 
      ~App ();
   
   private:
      MaquinaTuring *maquina;

      /* brief: exibe a tela do menu principal no console
      * pre: nenhuma
      * pos: informacoes do menu exibidas no console
      */ 
      void mostraMenu ();

      /* brief: carrega um arquivo txt com as informacoes da maquina de turing
      * pre: arquivo com sintaxe adequada
      * pos: informacoes carregadas caso o arquivo exista
      */ 
      void carregaArquivo ();

      /* brief: processa uma cadeia na maquina de turing
      * pre: maquina de turing carregada
      * pos: cadeia processada caso nao entre em loop
      */ 
      void processaCadeia ();

      //estados do menu principal
      enum Menu {CARREGA = 1, PROCESSA, SAIR};
};

#endif // !APP_HPP