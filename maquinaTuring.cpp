#include <fstream>
#include <iostream>

#include "MaquinaTuring.hpp"
#include "Destino.hpp"
#include "Util.hpp"

/* brief: construtor da classe: inicializa a maquina e sua fita
* pre: nenhuma
* pos: maquina inicializada
*/
MaquinaTuring::MaquinaTuring () : Fita() {}

/* brief: carrega a maquina de turing a partir de um arquivo txt
* param: nome do arquivo
* pre: sintaxe do arquivo ser valida
* pos: ter carregado a maquina caso o arquivo exista
*/
void MaquinaTuring::carrega (const std::string &nomeArquivo)
{
   std::ifstream file(nomeArquivo, std::ios::in);
   if (file.fail()) throw "Arquivo nao encontrado!";

   this->transicoes.clear();
   this->estadosFinais.clear();

   Util::ignoraAte(file, '\n'); //ignora a linha de estados
   this->carregaFinais(file);
   Util::ignoraAte(file, '\n'); //ignora a linha de alfabeto
   this->carregaTransicoes(file);
   file.close();
}

/* brief: carrega os estados finais da maquina a partir de um arquivo txt
* param: buffer de leitura de arquivo txt
* pre: cursor do arquivo estar posicionado na posicao correta
* pos: ter os estados finais carregados
*/
void MaquinaTuring::carregaFinais (std::ifstream &file)
{
   char c;
   int temp;

   while (file.get(c) && c != '\n')
      if (c == 'q')
      {
         file >> temp;
         this->estadosFinais.insert(temp);
      }
}

/* brief: carrega as transicoes da maquina a partir de um arquivo txt
* param: buffer de leitura de arquivo txt
* pre: cursor do arquivo estar posicionado na posicao correta
* pos: ter as transicoes carregadas
*/
void MaquinaTuring::carregaTransicoes (std::ifstream &file)
{
   while (!file.eof())
   {
      std::string chave;
      Destino dest;
      int  estadoTemp;
      char simboloTemp;

      //leitura do estado de partida. Ex: (q1,a)
      Util::ignoraAte(file, 'q');
      file >> estadoTemp;
      Util::ignoraAte(file, ',');
      do { file >> simboloTemp; } while (simboloTemp == ' ');
      chave = Util::concatena(estadoTemp, simboloTemp);

      //leitura do estado de chegada. Ex: (q2,X,D)
      Util::ignoraAte(file, 'q');
      file >> dest.estado;
      Util::ignoraAte(file, ',');
      do { file >> dest.saida; } while (dest.saida == ' ');
      Util::ignoraAte(file, ',');
      do { file >> dest.direcao; } while (dest.direcao == ' ');
      Util::ignoraAte(file, '\n');
   
      transicoes.insert(std::make_pair(chave, dest));
   }
}

/* brief: processa uma cadeia na maquina de turing
* param: cadeia a ser processada
* pre: nenhuma
* pos: ter exibido os procedimentos do processamento da cadeia
*/
void MaquinaTuring::processa (const std::string &str)
{
   //adiciona a fita na maquina
   Fita::add(str);
   Fita::showFita();

   while (this->existeTransicao(Util::concatena(atual, cadeia[posFita])))
   {
      //atualiza a fita
      Destino temp = this->transicoes[Util::concatena(atual, cadeia[posFita])];
      cadeia[posFita] = temp.saida;
      this->atual = temp.estado;
      (temp.direcao == 'D') ? ++posFita : --posFita;

      Fita::showFita();
   }
   
   if (this->ehEstadoFinal(atual))
      std::cout << "\nCadeia aceita!\n";
   else
      std::cout << "\nCadeia rejeitada!\n";
}

/* brief: funcao que verifica se um determinado estado eh estado final
* param: estado a ser checado
* return: true: eh estado final. false: caso contrario
* pre: nenhuma
* pos: nenhuma
*/
bool MaquinaTuring::ehEstadoFinal (int other) const
{
   return (this->estadosFinais.find(other) != this->estadosFinais.end());
}

/* brief: funcao que verifica se existe uma determinada transicao possivel
* param: string -> chave contendo estado e simbolo atual da fita
* return: true: existe transicao. false: caso contrario
* pre: nenhuma
* pos: nenhuma
*/
bool MaquinaTuring::existeTransicao (std::string str) const
{
   return (this->transicoes.find(str) != this->transicoes.end());
}