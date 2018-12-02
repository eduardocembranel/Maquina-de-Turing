#include <iostream>

#include "App.hpp"
#include "Util.hpp"

/* brief: construtor que aloca e inicializa a maquina de turing
* param: argumentos passados pela linha de comando
* pre: nenhuma
* pos: variavel alocada
*/ 
App::App (int argc, char **argv)
{
   this->maquina = new MaquinaTuring();

   //carrega a maquina
   if (argc > 1)
   {
      try
      {
         this->maquina->carrega(argv[1]);
         std::cout << "\nArquivo carregado com sucesso!\n";
      }
      catch (const char *erro)
      {
         std::cerr << "\n" << erro << "\n";
      }
      Util::pressRetornar();
   }
}

/* brief: metodo responsavel por iniciar e executar o programa
* pre: nenhuma
* pos: nenhuma
*/ 
void App::run ()
{
   int escolha; 
   do 
   {
      this->mostraMenu();
      std::cin >> escolha;
      Util::flushInput();
      switch (escolha)
      {
         case CARREGA:
            this->carregaArquivo();
            break;
         case PROCESSA:
            this->processaCadeia();
            break;
         case SAIR:
            break;
         default:
            std::cout << "\nOpcao invalida!\n";
            Util::pressRetornar();
      }
   } while  (escolha != SAIR);
}

/* brief: exibe a tela do menu principal no console
* pre: nenhuma
* pos: informacoes do menu exibidas no console
*/ 
void App::mostraMenu ()
{
   Util::clear();
   std::cout << "[MAQUINA DE TURING LIMITADA]\n\n"
             << "[1] Carregar maquina\n"
             << "[2] Processa cadeia\n"
             << "[3] Sair\n\n"
             << ">> ";
}

/* brief: carrega um arquivo txt com as informacoes da maquina de turing
* pre: arquivo com sintaxe adequada
* pos: informacoes carregadas caso o arquivo exista
*/ 
void App::carregaArquivo ()
{
   Util::clear();
   std::cout << "[Carregar maquina de Turing]\n\n"
             << "Insira o nome do arquivo: ";
   std::string fileName;
   std::cin >> fileName;
   Util::flushInput();
   try
   {
      maquina->carrega(fileName);
      std::cout << "\nArquivo carregado com sucesso!\n";
   }
   catch (const char *erro)
   {
      std::cerr << "\n" << erro << "\n";
   }
   Util::pressRetornar();
}

/* brief: processa uma cadeia na maquina de turing
* pre: maquina de turing carregada
* pos: cadeia processada caso nao entre em loop
*/ 
void App::processaCadeia ()
{
   Util::clear();
   std::cout << "[Processamento de cadeia]\n\n"
             << "Insira a cadeia a ser processada: ";
   std::string cadeia;
   std::cin >> cadeia;
   Util::flushInput();
   
   maquina->processa(cadeia);
   Util::pressRetornar();
}

/* brief: Destrutor da classe: desaloca o espaco de maquina de turing
* pre: maquina de turing alocada
* pos: variavel desalocada da memoria
*/ 
App::~App ()
{
   delete this->maquina;
}