#ifndef TEXTO_H
#define TEXTO_H

#include <string>
#include <vector>

#include "Palavra.h"

#define MAX 10000

class Texto {
private:
	std::string nomeArquivoOriginal;
	std::vector<Palavra> palavras;
public:
	void carregarTexto(std::string nomeArquivo);
	const std::vector<Palavra> &obterPalavras();
	void alterarPalavra(int indice, Palavra palavra);
	void gravarTexto(std::string nomeArquivo);
};

#endif