#include "Dicionario.h"

#include <fstream>

using namespace std;

Dicionario::Dicionario() {
	this->carregarPalavras();
}

std::vector<Palavra> Dicionario::obterSemelhantes(Palavra palavra) {
	std::vector<Palavra> semelhantes;

	for (auto teste : this->palavras)
		if (palavra.semelhante(teste))
			semelhantes.push_back(teste);

	return semelhantes;
}

void Dicionario::inserir(Palavra palavra) {
	this->palavras.insert(palavra);
}

bool Dicionario::encontrar(Palavra palavra) {
	return this->palavras.find(palavra) != this->palavras.end();
}

void Dicionario::gravarDicionario() {
	fstream arquivo("dic.txt");

	
}

void Dicionario::carregarPalavras() {
	fstream arquivo("dic.txt");

	string palavra;
	while (arquivo >> palavra)
		this->inserir(Palavra(palavra));
}
