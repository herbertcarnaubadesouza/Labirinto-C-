#include <array>

struct Posicao {
	int x, y;
};
const int TAM_LABIRINTO = 20 * 21;//tamanho do labirinto

using Tipo = Posicao;

class Pilha
{
private:
	std::array<Tipo, TAM_LABIRINTO> vetor; //Tipo e tamanho
	int topo_da_pilha;

public:
	Pilha();//construtor
	void push(Tipo elemento); //insere
	void pop(); //remove
	Tipo topo(); //mostra o elemento na ultima posição que possui registro
	bool vazia();
	bool cheia();
};

