
// TAMARA HUERTAS SMOLIS
// DA14

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"

struct extremos{
	int w;
	int e;
};

bool operator< (extremos const& a, extremos const& b) {
	return a.e < b.e;
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(PriorityQueue<extremos> &cola) {
	int sol = 1;
	int fin = cola.top().e;
	cola.pop();

	while (!cola.empty()) {
		if (cola.top().w >= fin) {
			sol++;
			fin = cola.top().e;
		}
		cola.pop();
	}

	return sol;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int n;
	std::cin >> n;

	if (n == 0)
		return false;

	int w, e;
	PriorityQueue<extremos> edificios;

	for (int i = 0; i < n; i++) {
		std::cin >> w >> e;
		edificios.push({ w, e });
	}


	int sol = resolver(edificios);

	// escribir sol
	std::cout << sol << std::endl;

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
