// TAMARA HUETAS SMOLIS
// DA14

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// O(n) donde n es el numero de elementos del vector de defensas
int resolver(std::vector<int> const& ciudades, std::vector<int> const& defensas) {
	int sol = 0;
	int c = 0, d = 0; 
	
	while (d < defensas.size()) {
		if (ciudades[c] <= defensas[d]) {
			sol++;
			c++;
			d++;
		}
		else {
			d++;
		}
	}

	return sol;
}

// O(n + nlogn + n + nlogn) -> O(n log n) donde n es el numero de elementos de los vectores de ciudades y defensas, que es el mismo
bool resuelveCaso() {

	// leer los datos de la entrada
	int n;

	std::cin >> n;

	if (!std::cin)  // fin de la entrada
		return false;

	int ciudad, defensa;
	std::vector<int> ciu;
	std::vector<int> def;

	for (int i = 0; i < n; i++) {
		std::cin >> ciudad;
		ciu.push_back(ciudad);
	}

	std::sort(ciu.begin(), ciu.end()); // O(n log n)

	for (int i = 0; i < n; i++) {
		std::cin >> defensa;
		def.push_back(defensa);
	}

	std::sort(def.begin(), def.end()); // // O(n log n)

	// escribir sol

	int sol = resolver(ciu, def);
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
