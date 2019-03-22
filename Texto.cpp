#include "Texto.h"

#include <fstream>

using namespace std;

void Texto::carregarTexto(std::string nomeArquivo) {
	fstream arquivo(nomeArquivo);

	string palavra;
	while (arquivo >> palavra)
		palavras.push_back(Palavra(palavra));
}

const std::vector<Palavra>& Texto::obterPalavras() {
	return palavras;
}

void Texto::alterarPalavra(int indice, Palavra palavra) {
	this->palavras[indice] = palavra;
}

void Texto::gravarTexto(std::string nomeArquivo) {
	fstream arquivo(nomeArquivo);

	for (auto palavra : this->palavras)
		arquivo << palavra.getValor() << " ";
}
