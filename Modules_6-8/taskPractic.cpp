// Персональный шаблон
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
struct triangle {
	double a = 0;
	double b = 0;
	double c = 0;
};
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = begin + rand() % (end-begin);
}
template <typename T>
void show_arr(T arr[], const int length) {
	if (length <= 0)
		throw std::invalid_argument("Длинна массива должна быть больше нуля");

	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
double tr_area(triangle& T);
template <typename T>
void append(T *&arr, int length, T val) {
	T* tmp = new T[length + 1]{};
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	tmp[length] = val;
	delete[]arr;
	arr = tmp; //указатель arr направлен на область памяти tmp
}
template <typename T>
void memory(T *& ptr, int length);
template <typename T>
T* posArr_concat(T arr1[],const int length1,T arr2[],const int length2, int &num);
int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	//Задача 1.Выделение памяти
	
	std::cout << "задача 1\nВведите количество элементов массива -> ";
	std::cin >> n;
	int* pArr1 = nullptr; 
	try	{
		memory(pArr1, n);
		fill_arr(pArr1, n, 2, 8);
		std::cout << "Итоговый массив: ";
		show_arr(pArr1, n);
		std::cout << "\n";
		delete pArr1;
	}
	catch (const std::out_of_range& ex){
		std::cout << "Ошибка: " << ex.what() << "\n\n";
	}
	
	//Задача 2.Положительные числа двух массивов
	
	std::cout << "Задача 2\n";
	const int size1 = 7, size2 = 5;
	int arr1[size1]{};
	int arr2[size2]{};
	fill_arr(arr1, size1, -5, 6);
	fill_arr(arr2, size2, -10, 10);
	std::cout << "Массив 1: ";
	show_arr(arr1, size1);
	std::cout << "Массив 2: ";
	show_arr(arr2, size2);
	int* result_arr = posArr_concat(arr1, size1, arr2, size2, n);
	std::cout << "Итоговый массив: ";
	show_arr(result_arr, n);
	std::cout << std::endl;
	delete[] result_arr;
	
	//Задача 3.Площадь произвольного треугольника
	std::cout << "Задача 3\nСтороны треугольника: ";
	triangle abc{ 5.5,10.0,9.1 };
	std::cout << abc.a << ", " << abc.b << ", " << abc.c << '\n';
	std::cout << "Площадь треугольника = " << tr_area(abc) << "\n\n";
	

	return 0;
}
//Выделяет память под массив
template <typename T>
void memory(T*& ptr, int length) {
	if (length < 0)
		throw std::out_of_range("Длинна массива должна быть положительной!");
	ptr = new T[length];
}
//переносит положительные числа из двух массивов в третий массив
template <typename T>
T* posArr_concat(T arr1[], const int length1, T arr2[], const int length2, int& num) {
	T* tmp_Arr = new T[0];
	int tmp_size = 0;
	for(int i=0;i<length1;i++)
		if (arr1[i] > 0) {
			append(tmp_Arr, tmp_size, arr1[i]);
			tmp_size++;
		}
	for (int i = 0; i < length2; i++)
		if (arr2[i] > 0) {
			append(tmp_Arr, tmp_size, arr2[i]);
			tmp_size++;
		}
	num = tmp_size;
	return tmp_Arr;
}
//нахождения площади треугольника по трем сторонам
double tr_area(triangle& T) {
	double halfp = (T.a + T.b + T.c) / 2.0;
	return sqrt(halfp*(halfp-T.a) * (halfp - T.b) * (halfp - T.c));
}