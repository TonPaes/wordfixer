#include "Corretor.h"

Corretor::Corretor(std::string nomeArquivo) {
	// Carregar texto do arquivo de texto
	this->texto.carregarTexto(nomeArquivo);

	// Iniciar variaveis auxiliares para correcao
	this->indicePalavra = -1;
	this->irParaProximoErro();
}

bool Corretor::existemErros() {
	// Existem erros se o indice da palavra e menor do que o numero de palavras
	return this->indicePalavra < (int)this->texto.obterPalavras().size();
}

Palavra Corretor::obterPalavraErrada() {
	// A palavra atual e incorreta
	return this->obterPalavraAtual();
}

Palavra Corretor::obterPalavraAnterior() {
	// Retornar palavra anterior somente se possivel
	return this->indicePalavra > 0 ? this->texto.obterPalavras()[this->indicePalavra - 1] : Palavra("");
}

Palavra Corretor::obterPalavraSeguinte() {
	// Retorna palavra seguinte somente se possivel
	return this->indicePalavra < this->texto.obterPalavras().size() - 1 ? this->texto.obterPalavras()[this->indicePalavra + 1] : Palavra("");
}

std::vector<Palavra> Corretor::obterSemelhantes() {
	// Utiliza a funcao do dicionario para obter semelhantes
	return this->dicionario.obterSemelhantes(this->obterPalavraErrada());
}

Palavra Corretor::obterPalavraAtual() {
	// Utiliza a funcao do texto para obter a palavra atual
	return this->texto.obterPalavras()[this->indicePalavra];
}

void Corretor::irParaProximoErro() {
	// Funcao para encontrar o proximo erro 
	while (this->indicePalavra < (int)this->texto.obterPalavras().size()) {
		// Incrementar indice da palavra
		if (++this->indicePalavra >= this->texto.obterPalavras().size())
			return;

		// Obter palavra atual
		Palavra palavraAtual = this->obterPalavraAtual();

		// Verificar se é errada
		if (!this->dicionario.encontrar(palavraAtual))
			break;

		// A palavra errada é incrementada na função
		this->errada.incrementarErro(palavraAtual);
	}
}

void Corretor::corrigirPalavra(Palavra palavra) {
	// Utilizar a funcao do texto para corrigir a palavra passada como parâmetro
	this->texto.alterarPalavra(indicePalavra, palavra);

	irParaProximoErro();
}

void Corretor::ignorarErro() {
	// Vai para o próximo erro, apenas salvando a palavra errada no vetor
	irParaProximoErro();
}

void Corretor::adicionarPalavraAoDicionario() {
	// Utiliza a funcao do dicionario para salvar a palavra errada ao dicionario
	this->dicionario.inserir(this->obterPalavraAtual());
	irParaProximoErro();
}

void Corretor::gravarTexto(std::string nomeArquivo) {
	// Salva o texto modificado no arquivo
	this->texto.gravarTexto(nomeArquivo);
}

void Corretor::gravarDicionario() {
	// Salva o dicionário modificado no arquivo
	this->dicionario.gravarDicionario();
}
