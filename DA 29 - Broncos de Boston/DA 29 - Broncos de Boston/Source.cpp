#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


// función que resuelve el problema 
// O(n) donde n es el número de los vectores r (rivales) y b(broncos) que es el mismo

int resolver(std::vector<int> const& r, std::vector<int> const& b) {
	int sol = 0;

	// solo recorremos uno de los dos vectores ya que los dos van a atener el mismo 
	//   número de elementos para poder comparar por parejas
	for (int i = 0; i < b.size(); i++) {
		if (b[i] > r[i]) {
			sol += (b[i] - r[i]);
		}
	}
	return sol;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
//coste total: O(n + n + nlogn + nlogn + n) --> O(3n + 2nlogn) --> O(nlogn)

bool resuelveCaso() {

	// leer los datos de la entrada
	int n, elem;
	std::cin >> n;

	if (n == 0)
		return false;

	std::vector<int> rivales;
	std::vector<int> broncos;

	// n va a ser igual en ambos vectores

	// O(n) donde n es el número de rivales
	for (int i = 0; i < n; i++) {
		std::cin >> elem;
		rivales.push_back(elem);
	}

	// O(n) donde n es el número de broncos
	for (int j = 0; j < n; j++) {
		std::cin >> elem;
		broncos.push_back(elem);
	}

	// O(nlogn) donde n es el número de elementos del vector rivales
	// orden de menor a mayor
	std::sort(rivales.begin(), rivales.end());

	// O(nlogn) donde n es el número de elementos del vector broncos
	// orden de mayor a menor
	std::sort(broncos.begin(), broncos.end(), std::greater<int>());

	int sol = resolver(rivales, broncos); // O(n)

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