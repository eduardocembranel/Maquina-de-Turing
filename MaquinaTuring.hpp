#ifndef MAQUINATURING_HPP
#define MAQUINATURING_HPP

/*
* \file MaquinaTuring.hpp
* \class MaquinaTuring
* \brief Classe que representa uma maquina de turing
* \author Eduardo Cembranel 
* \author Guilherme Maci
* \author Lucas Rodrigues
* \author Ysyo Socorro
*/

#include <unordered_map>
#include <unordered_set>
#include <string>

#include "Destino.hpp"
#include "Fita.hpp"

class MaquinaTuring : public Fita
{
   public:
      /* brief: construtor da classe: inicializa a maquina e sua fita
      * pre: nenhuma
      * pos: maquina inicializada
      */
      MaquinaTuring ();

      /* brief: carrega a maquina de turing a partir de um arquivo txt
      * param: nome do arquivo
      * pre: sintaxe do arquivo ser valida
      * pos: ter carregado a maquina caso o arquivo exista
      */
      void carrega (const std::string &);

      /* brief: processa uma cadeia na maquina de turing
      * param: cadeia a ser processada
      * pre: nenhuma
      * pos: ter exibido os procedimentos do processamento da cadeia
      */
      void processa (const std::string &);
   
   private:
      std::unordered_map<std::string, Destino> transicoes; //tabela de transicoes
      std::unordered_set<int> estadosFinais; //tabela de estados finais
      const int estadoInicial{0}; //estado inicial

      /* brief: carrega os estados finais da maquina a partir de um arquivo txt
      * param: buffer de leitura de arquivo txt
      * pre: cursor do arquivo estar posicionado na posicao correta
      * pos: ter os estados finais carregados
      */
      void carregaFinais (std::ifstream &);

      /* brief: carrega as transicoes da maquina a partir de um arquivo txt
      * param: buffer de leitura de arquivo txt
      * pre: cursor do arquivo estar posicionado na posicao correta
      * pos: ter as transicoes carregadas
      */
      void carregaTransicoes (std::ifstream &);

      /* brief: funcao que verifica se um determinado estado eh estado final
      * param: estado a ser checado
      * return: true: eh estado final. false: caso contrario
      * pre: nenhuma
      * pos: nenhuma
      */
      bool ehEstadoFinal (int) const;

      /* brief: funcao que verifica se existe uma determinada transicao possivel
      * param: string -> chave contendo estado e simbolo atual da fita
      * return: true: existe transicao. false: caso contrario
      * pre: nenhuma
      * pos: nenhuma
      */
      bool existeTransicao (std::string) const;

};

#endif // !MAQUINATURING_HPP