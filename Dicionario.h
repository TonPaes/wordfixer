#ifndef DICIONARIO_H
#define DICIONARIO_H

#include <vector>
#include <set>

#include "Arvore.h"
#include "Palavra.h"

class Dicionario {
public:
	Dicionario();

	std::vector<Palavra> obterSemelhantes(Palavra palavra);
	void inserir(Palavra palavra);
	bool encontrar(Palavra palavra);

	void gravarDicionario();
private:
	//Arvore palavras;
	std::set<Palavra> palavras;

	void carregarPalavras();
};

#endif