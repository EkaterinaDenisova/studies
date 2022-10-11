// Автор: Денисова Екатерина
// заголовочный файл модуля

#include <vector>
#include <string> //строки

using vector_int = std::vector<int>;

// пользовательское пространство имён с функциями
namespace arrf {
	/// заполнение файла filename случайными числами (количеством n) из промежутка [nmin...nmax]
	void write_random_to_file (std::string filename, int n, int nmin, int nmax);

	/// вывод вектора v размерностью n в консоль
	void output_vector (const vector_int &v);

	/// заполнение вектора v значениями из файла filename
	void read_vector_from_file (vector_int &v, const std::string &filename);

	/// перемножение элементов вектора v размером n
	float multiplication (const vector_int &v);
}