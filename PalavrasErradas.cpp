#include "PalavrasErradas.h"

void PalavrasErradas::incrementarErro(Palavra palavra) {
	// Mapa que salva para cada palavra a quantidade de vezes ocorrida
	++erroPalavra[palavra];
}
