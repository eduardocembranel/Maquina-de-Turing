#include <iostream>
#include <limits>
#include <cstdlib>

#include "Util.hpp"

/* brief: construtor privado, impossibilitando a instancia de objetos
* pre: nenhuma
* pos: nenhuma
*/
Util::Util () {}

/* brief: limpa a tela do console
* pre: nenhuma
* pos: tela limpada do console
*/
void Util::clear ()
{
   system("cls");
}

/* brief: exibe a mensagem esperando por um ENTER e aguarda o mesmo
* pre: buffer de entrada esta limpo
* pos: nenhuma
*/
void Util::pressRetornar ()
{
   std::cout << "\nPressione ENTER para retornar...";
   Util::flushInput();
}

/* brief: limpa os dados de entrada, para tirar espaços desnescessários
* pre: nenhuma
* pos:ter retirado os espaços desnecessários
*/
void Util::flushInput ()
{
   std::cin.clear();
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/* brief: ignora os caracteres de um arquivo txt ate um caracter
* determinado ser lido
* param: buffer de leitura de arquivo e caracter de parada
* pre: arquivo aberto
* pos: ter o cursor posicionado logo apos o caracter de parada
*/
void Util::ignoraAte (std::ifstream &file, char c)
{
   char ch;
   while (file.get(ch) && ch != c)
      {}
}

/* brief: concatena um int e char separados por \n na forma de string 
* param: inteiro e caracter a serem concatenados
* return: string concatenada
* pre: nenhuma
* pos: ter retornado a string concatenada
*/
std::string Util::concatena (int i, char c)
{
   return std::to_string(i) + "\n" + std::to_string(c);
}