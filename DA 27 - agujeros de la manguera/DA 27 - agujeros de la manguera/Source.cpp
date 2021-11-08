// TAMARA HUETAS SMOLIS
// DA14

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(std::vector<int> const& v, int l) {
	int solu = 1;
	int ini = v[0];

	for (int i = 1; i < v.size(); i++) {
		if (ini + l < v[i]) {
			solu++;
			ini = v[i];
		}
	}

	return solu;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int n, l;

	std::cin >> n >> l;

	if (!std::cin)  // fin de la entrada
		return false;

	int agujero;
	std::vector<int> agujeros;

	for (int i = 0; i < n; i++) {
		std::cin >> agujero;
		agujeros.push_back(agujero);
	}

	// escribir sol

	int sol = resolver(agujeros, l);
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
