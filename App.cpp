#include <iostream>

#include "App.hpp"
#include "Util.hpp"

App::App ()
{
   this->maquina = new MaquinaTuring();
}

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

void App::mostraMenu ()
{
   Util::clear();
   std::cout << "[MAQUINA DE TURING LIMITADA]\n\n"
             << "[1] Carregar maquina\n"
             << "[2] Processa cadeia\n"
             << "[3] Sair\n\n"
             << ">> ";
}

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
      maquina->carregaMaquina(fileName);
      std::cout << "\nArquivo carregado com sucesso!\n";
   }
   catch (const char* erro)
   {
      std::cerr << "\n" << erro << "\n";
   }
   Util::pressRetornar();
}

void App::processaCadeia ()
{
   Util::clear();
   std::cout << "[Processamento de cadeia]\n\n"
             << "Insira a cadeia a ser processada: ";
   std::string cadeia;
   std::cin >> cadeia;
   Util::flushInput();
   try
   {
      maquina->processa(cadeia);
      std::cout << "\nCadeia aceita!\n";
   }
   catch (const char *erro)
   {
      std::cerr << "\n" << erro << "\n";
   }
   Util::pressRetornar();
}

App::~App ()
{
   delete this->maquina;
}