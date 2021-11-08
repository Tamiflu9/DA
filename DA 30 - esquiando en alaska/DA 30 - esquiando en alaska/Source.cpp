
// TAMARA HUERTAS SMOLIS 
// DA14

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(std::vector<int> const& esquiadores, std::vector<int> const& esquis) {
	int sol = 0;

	for (int i = 0; i < esquiadores.size(); i++) {
		sol += std::abs(esquiadores[i] - esquis[i]);
	}

	return sol;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int n, elem;
	std::cin >> n;

	if (n == 0)
		return false;

	std::vector<int> esquiadores;
	std::vector<int> esquis;

	for (int i = 0; i < n; i++) {
		std::cin >> elem;
		esquiadores.push_back(elem);
	}

	for (int j = 0; j < n; j++) {
		std::cin >> elem;
		esquis.push_back(elem);
	}

	std::sort(esquiadores.begin(), esquiadores.end());
	std::sort(esquis.begin(), esquis.end());

	int sol = resolver(esquiadores, esquis);

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
