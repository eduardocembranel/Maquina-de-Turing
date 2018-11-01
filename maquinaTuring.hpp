#ifndef MAQUINATURING_HPP
#define MAQUINATURING_HPP

#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>

#include "Destino.hpp"
#include "Fita.hpp"

class MaquinaTuring : public Fita
{
   public:
      MaquinaTuring ();
      void carregaMaquina (const std::string &);
      void processa (const std::string &);
      void teste ();
   
   private:
      std::unordered_map<std::string, Destino> transicoes;
      std::unordered_set<int> estadosFinais;
      const int estadoInicial{0};

      void carregaFinais (std::ifstream &);
      void carregaTransicoes (std::ifstream &);
      bool ehEstadoFinal (int) const;
      bool existeTransicao (std::string) const;

};

#endif // !MAQUINATURING_HPP