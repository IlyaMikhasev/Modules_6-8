// ������������ ������
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
		throw std::invalid_argument("������ ������� ������ ���� ������ ����");

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
	arr = tmp; //��������� arr ��������� �� ������� ������ tmp
}
template <typename T>
void memory(T *& ptr, int length);
template <typename T>
T* posArr_concat(T arr1[],const int length1,T arr2[],const int length2, int &num);
int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	//������ 1.��������� ������
	
	std::cout << "������ 1\n������� ���������� ��������� ������� -> ";
	std::cin >> n;
	int* pArr1 = nullptr; 
	try	{
		memory(pArr1, n);
		fill_arr(pArr1, n, 2, 8);
		std::cout << "�������� ������: ";
		show_arr(pArr1, n);
		std::cout << "\n";
		delete pArr1;
	}
	catch (const std::out_of_range& ex){
		std::cout << "������: " << ex.what() << "\n\n";
	}
	
	//������ 2.������������� ����� ���� ��������
	
	std::cout << "������ 2\n";
	const int size1 = 7, size2 = 5;
	int arr1[size1]{};
	int arr2[size2]{};
	fill_arr(arr1, size1, -5, 6);
	fill_arr(arr2, size2, -10, 10);
	std::cout << "������ 1: ";
	show_arr(arr1, size1);
	std::cout << "������ 2: ";
	show_arr(arr2, size2);
	int* result_arr = posArr_concat(arr1, size1, arr2, size2, n);
	std::cout << "�������� ������: ";
	show_arr(result_arr, n);
	std::cout << std::endl;
	delete[] resault_arr;
	
	//������ 3.������� ������������� ������������
	std::cout << "������ 3\n������� ������������: ";
	triangle abc{ 5.5,10.0,9.1 };
	std::cout << abc.a << ", " << abc.b << ", " << abc.c << '\n';
	std::cout << "������� ������������ = " << tr_area(abc) << "\n\n";
	

	return 0;
}
//�������� ������ ��� ������
template <typename T>
void memory(T*& ptr, int length) {
	if (length < 0)
		throw std::out_of_range("������ ������� ������ ���� �������������!");
	ptr = new T[length];
}
//��������� ������������� ����� �� ���� �������� � ������ ������
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
//���������� ������� ������������ �� ���� ��������
double tr_area(triangle& T) {
	double halfp = (T.a + T.b + T.c) / 2.0;
	return sqrt(halfp*(halfp-T.a) * (halfp - T.b) * (halfp - T.c));
}