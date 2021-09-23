#include "Pilha.h" //include do .h
#include <iostream>


using namespace std;

//construtor sem parâmetro mas iniciando topo com - 1(vazia)
Pilha::Pilha() {
	topo_da_pilha = -1;
}


void Pilha::push(Tipo elemento) {
	if (cheia())
	{
		cerr << "Pilha cheia!" << endl;
	}
	else
	{
		vetor[++topo_da_pilha] = elemento; //inserindo na próxima posição do vetor
	}
}

void Pilha::pop() {
	if (vazia())
	{
		cerr << "Pilha vazia!" << endl;
	}
	else
	{
		--topo_da_pilha; //Removendo a última posição do vetor
	}
}

Tipo Pilha::topo() {
	if (vazia())
	{
		cerr << "Pilha vazia!" << endl;
		return Tipo{};
	}
	else
	{
		return vetor[topo_da_pilha]; //retorna o último registro do vetor
	}
}

bool Pilha::vazia() {
	return topo_da_pilha == -1;
}

bool Pilha::cheia() {
	return topo_da_pilha == TAM_LABIRINTO - 1; // -1 porque o zero conta
}