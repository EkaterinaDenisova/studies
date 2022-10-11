// Автор: Денисова Екатерина
// Даны натуральное число n,
// действительные числа a1,..., an. Вычислить:
// б) a1a2 ... an;


#include <iostream> // модуль для ввода/вывода в консоль
#include <math.h>  // математические функции
#include <ctime>
#include "vec.h"  // модуль с функциями
#include <exception>
#include <fstream> // работа с файлами
#include <string> //строки

using namespace std;  // std - стандартное пространство имён
using namespace arrf; // arrf - пользовательское пространство имён с функциями для работы с массивом

int main () {
	string filename = "data"; // имя файла
	int n; // число элементов массива
	float count; // произведение элементов массива

	cout << "Enter number of elements in array: ";
	cin >> n; // получение от пользователя размера массива

	try {
		srand(time(0)); // инициализация генератора случайных чисел
		write_random_to_file(filename,n,1,10); // заполнение файла случайными числами

		vector_int arr;   // вектор, или динамический массив (пока пустой)
		arr.resize(n);    // изменение размера вектора

		read_vector_from_file(arr, filename);
		output_vector(arr); // вывод массива

		count = multiplication(arr); // произведение элементов массива
		cout << "\nMultiplication = " << count;

		arr.clear();                // освобождение памяти 
	}
	catch (invalid_argument e) { //"ловим" исключения типа invalid_argument
		cout << e.what(); //what выводит сообщение, добавленное в функцию invalid_argument()
	}

    return 0;
}