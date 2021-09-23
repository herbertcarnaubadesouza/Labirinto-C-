
#include <iostream>
#include <vector>
#include <string>
#include "Pilha.h"

using namespace std;

bool caminho(vector<string> labirinto, Posicao pos, Pilha& pilha) {

	if (labirinto[pos.x][pos.y] == 'S')
	{
		pilha.push(pos);
		cout << "--------------------\n";
		cout << "||FIM DO LABIRINTO||\n";
		cout << "--------------------\n";
		return false;
	}
	//Posição Válida: um caracter branco e dentro do escopo do labririnto	
	if (pos.x >= 0 && pos.x < labirinto.size() &&
		pos.y >= 0 && pos.y < labirinto[0].size()  /*Deve ser menor que uma linha do labirinto*/)
	{
		//labirinto[pos.x][pos.y]

		if (labirinto[pos.x + 1][pos.y] == 'S' || labirinto[pos.x + 1][pos.y] == ' '/*Descendo*/)
		{
			//estanciando a struct
			Posicao posNova{
				pos.x + 1, pos.y
			};
			labirinto[pos.x][pos.y] = '*';
			pilha.push(pos);
			return caminho(labirinto, posNova, pilha);
		}
		if (labirinto[pos.x][pos.y + 1] == 'S' || labirinto[pos.x][pos.y + 1] == ' '/*Direita*/)
		{
			//estanciando a struct
			Posicao posNova{
				pos.x, pos.y + 1
			};
			labirinto[pos.x][pos.y] = '*';
			pilha.push(pos);
			return caminho(labirinto, posNova, pilha);
		}

		if (labirinto[pos.x - 1][pos.y] == 'S' || labirinto[pos.x - 1][pos.y] == ' '/*Subindo*/)
		{
			//estanciando a struct
			Posicao posNova{
				pos.x - 1, pos.y
			};
			labirinto[pos.x][pos.y] = '*';
			pilha.push(pos);
			return caminho(labirinto, posNova, pilha);
		}
		if (labirinto[pos.x][pos.y - 1] == 'S' || labirinto[pos.x][pos.y - 1] == ' '/*Esquerda*/)
		{
			//estanciando a struct
			Posicao posNova{
				pos.x, pos.y - 1
			};
			labirinto[pos.x][pos.y] = '*';
			pilha.push(pos);//tem que adicionar a de agora para ele dar o return na posição da frente
			return caminho(labirinto, posNova, pilha);
		}

		if (!pilha.vazia()) //caso a pilha não seja vazia
		{
			labirinto[pos.x][pos.y] = '!'; //Se não fizer isso ele vai tentar o caminho de novo, tem que marcar como erro
			pos = pilha.topo(); //pegando a última posição da pilha
			pilha.pop();
			return caminho(labirinto, pos, pilha);
		}


	}
	return false; // sem caminho válido

}





int main()
{
	//Copiando o vetor de string do professor
	vector<string> labirinto = {
		"XXXXXXXXXXXXXXXXXXXXX",//x
		"X     X     X     X X",
		"XX XX XXXXX X X X   X",
		"X   X       XXX XXX X",
		"X X X XXXXXXX   X   X",
		"X X   X   X X X   X X",
		"X XXXXX X X   XXXXX X",
		"X X     X XXX  X    X",
		"X X X X X   XX XX XXX",
		"X X XXX X X     X   X",
		"E X X X X XXXXX XXX X",
		"X     X X   X X X   X",
		"X XXXXX XXX X XXX X X",
		"X X       X X   X X X",
		"X   XXX X X XXX X X X",
		"XXX X X X X X X X XXX",
		"X X   X X   X   X   X",
		"X XXX XXXXXXXXX XXX X",
		"X                 X X",
		"XXXXXXXXXXXXXXXXXXXSX"
		//y
	};

	Posicao posicao_E{
		10,0
	};

	Pilha pilha;

	caminho(labirinto, posicao_E, pilha);

	while (!pilha.vazia()) //enquanto não estiver vazia
	{
		labirinto[pilha.topo().x][pilha.topo().y] = '*';
		pilha.pop();
	}


	cout << "** LABIRINTO **\n";
	cout << "\n";
	cout << "DAOO/PEDA - EP - PUCPR\n";
	cout << "Prof. Luiz Lima Jr.\n";
	cout << "\n";
	cout << "--------------------------------------\n";
	cout << "||                                  ||\n";
	cout << "|| Aluno: Herbert Carnauba de Souza ||\n";
	cout << "||                                  ||\n";
	cout << "--------------------------------------\n";
	cout << "\n";
	cout << "Entrada: (10,0)\n";
	cout << "\n";
	cout << "\n";
	
	for (int i = 0; i < labirinto.size(); i++)
	{
		cout << labirinto[i] << "\n";
	}

	cout << "\n";
	cout << "\n";
	cout << "Saida: (19,19)\n";
	

}

