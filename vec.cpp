// Автор: Денисова Екатерина
#include <iostream> // модуль для ввода/вывода в консоль
#include <math.h>  // математические функции
#include <ctime>   // для генерации случайных чисел
#include "vec.h"
#include <exception>
#include <fstream> // работа с файлами
#include <string> //строки

using namespace std;  // std - стандартнрое пространство имён


/// заполнение файла filename случайными числами (количеством n) из промежутка [nmin...nmax]
void arrf::write_random_to_file (string filename, int n, int nmin, int nmax) {	
	// precondition check 
	if (n <= 0) throw invalid_argument("Invalid size of array"); //неверная размерность массива
	
	if (nmin > nmax) {
		int p = nmin;
		nmin = nmax;
		nmax = p;
	}

	ofstream f(filename); //файл для записи
	cout << "n = " << n << endl;
    int x;
    for (unsigned i = 0; i<n; i++){
        x = (rand() % (nmax+1)) + nmin; //случайное число от nmin до nmax
        //cout << x << " ";
        f << x << endl; // записать x и символ перехода на новую строку в файл
    }
    //cout << endl;

    f.close();
}

/// заполнение вектора v значениями из файла с именем filename
void arrf::read_vector_from_file (vector_int &v, const string &filename) {
	if (v.empty()) throw invalid_argument("Array is empty"); //неверная размерность массива

	ifstream f_read; // файл для чтения
    f_read.open(filename);  // открытие файла
    
    if (f_read.is_open()){ // если открытие файла прошло успешно
		string buf; //в buf считывается одно строка из файла
		unsigned i = 0;
		while ( getline(f_read,buf) ){ //построчное чтение файла
			//cout << buf << " "; //вывод считанной строки в консоль
			v[i] = stoi(buf); // значение, считанное из файла, записывается в массив
			i++;
		}
		//cout << endl;
		f_read.close();
	}
	else throw invalid_argument("Could not open file");
}

/// вывод вектора v размерностью n в консоль
void arrf::output_vector (const vector_int &v) {
	if (v.empty()) throw invalid_argument("Array is empty"); //неверная размерность массива

	for(unsigned i = 0; i < v.size(); ++i) {
		if ((i+1) % 10 != 0)  //вывод элементов массива по 10 в строке
			cout << v[i] << " ";
		else cout << v[i] << "\n";
	}
}

/// перемножение элементов вектора v размером n
float arrf::multiplication (const vector_int &v) {
	if (v.empty()) throw invalid_argument("Array is empty"); //неверная размерность массива

	float res = 1;

	for (unsigned i = 0; i < v.size(); i++) {
		res *= v[i];
	}

	return res;
}