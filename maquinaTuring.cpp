#include <fstream>
#include <iostream>

#include "maquinaTuring.hpp"
#include "Destino.hpp"
#include "Util.hpp"

MaquinaTuring::MaquinaTuring () : Fita() {}

void MaquinaTuring::carregaMaquina (const std::string &nomeArquivo)
{
   this->transicoes.clear();
   std::ifstream file(nomeArquivo, std::ios::in);

   if (file.fail()) throw "Arquivo nao encontrado!";

   file.ignore(1, '\n');
   this->carregaFinais(file);
   file.ignore(1, '\n');
   this->carregaTransicoes(file);

   file.close();
}

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
   Util::ignoraAte(file, '\n');
}

void MaquinaTuring::carregaTransicoes (std::ifstream &file)
{
   while (!file.eof())
   {
      std::string chave;
      Destino dest;
      int  estadoTemp;
      char simboloTemp;

      //leitura do estado de partida. Ex: (q1,a)
      {
         Util::ignoraAte(file, 'q');
         file >> estadoTemp;
         Util::ignoraAte(file, ',');
         do { file >> simboloTemp; } while (simboloTemp == ' ');
         chave = Util::concatena(estadoTemp, simboloTemp);
      }

      //leitura do estado de chegada. Ex: (q2,X,D)
      {
         Util::ignoraAte(file, 'q');
         file >> dest.estado;
         Util::ignoraAte(file, ',');
         do { file >> dest.saida; } while (dest.saida == ' ');
         Util::ignoraAte(file, ',');
         char temp;
         do { file >> temp; } while (temp == ' ');
         (temp == 'E') ? dest.direcao = Destino::ESQUERDA : 
                         dest.direcao = Destino::DIREITA;
      }
      
      transicoes.insert(std::make_pair(chave, dest));
      Util::ignoraAte(file, '\n');
   }
}

void MaquinaTuring::teste ()
{
   // Chave chave(3, 'Y');
   // for (auto &it : transicoes)
   // {
   //    it.second.teste();
   //    std::cout << std::endl;
   // }
   // Util::pressRetornar();
}

void MaquinaTuring::processa (const std::string &str)
{
   //adiciona a fita na maquina
   Fita::add("*" + str + "$");
   Fita::showFita();

   while (this->existeTransicao(Util::concatena(atual, cadeia[posFita])))
   {
      //atualiza a fita
      Destino temp = this->transicoes[Util::concatena(atual, cadeia[posFita])];
      cadeia[posFita] = temp.saida;
      this->atual = temp.estado; 
      (temp.direcao == Destino::DIREITA) ? ++posFita : --posFita;

      Fita::showFita();
   }
   //caso a cadeia tenha sido rejeitada pela maquina
   if (!this->ehEstadoFinal(atual))
      throw "Cadeia rejeitada!";
}

bool MaquinaTuring::ehEstadoFinal (int other) const
{
   return (this->estadosFinais.find(other) != this->estadosFinais.end());
}

bool MaquinaTuring::existeTransicao (std::string str) const
{
   return (this->transicoes.find(str) != this->transicoes.end());
}