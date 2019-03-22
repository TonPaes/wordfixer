#ifndef CORRETOR_H
#define CORRETOR_H

#include <vector>

#include "Dicionario.h"
#include "Texto.h"
#include "Palavra.h"
#include "PalavrasErradas.h"

class Corretor {
public:
	Corretor(std::string nomeArquivo);

	bool existemErros();
	Palavra obterPalavraErrada();
	Palavra obterPalavraAnterior();
	Palavra obterPalavraSeguinte();
	std::vector<Palavra> obterSemelhantes();

	void corrigirPalavra(Palavra palavra);
	void ignorarErro();
	void adicionarPalavraAoDicionario();

	void gravarTexto(std::string nomeArquivo);
	void gravarDicionario();
private:
	Dicionario dicionario;
	Texto texto;
	PalavrasErradas errada;

	int indicePalavra;

	Palavra obterPalavraAtual();
	void irParaProximoErro();
};

#endif