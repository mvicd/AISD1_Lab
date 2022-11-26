#include <iostream>
#include "Set.h"
#include <conio.h>

int GetKey() noexcept {
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

int Ent() noexcept {
	while (true) {
		int key = GetKey();
		if (key == 13) return key;
	}
}

void Menu() {
	Set set;
	Set set_sec;
	while (true) {
		system("cls");
		std::cout << "\n1. Create empty set";
		std::cout << "\n2. Create N-count set";
		std::cout << "\n3. Add num to set";
		std::cout << "\n4. Subtract num to set";
		std::cout << "\n5. Get with []";
		std::cout << "\n6. Unification (+) two sets";
		std::cout << "\n7. Difference (-) two sets";
		std::cout << "\n8. Intersection two sets";
		std::cout << "\n9. Check to contain number in set";
		std::cout << "\nq. Duplicate numbers in array";
		std::cout << "\nw. Check for equality";
		std::cout << "\n0. Exit\n";
		int m = GetKey();
		if (m == 49) {
			system("cls");
			std::cout << "Set = {}\n";
			set = Set();
			Ent();
		}
		if (m == 50) {
			system("cls");
			size_t N = 0;
			std::cout << "Input N = size of set!\nN = ";
			std::cin >> N;
			set = Set(N);
			Ent();
		}
		if (m == 51) {
			system("cls");
			int num = 0;
			std::cout << "Input num to add set: ";
			std::cin >> num;
			set + num;

		}
		if (m == 52) {
			system("cls");
			int num = 0;
			std::cout << "Input num to delete set: ";
			std::cin >> num;
			set - num;

		}
		if (m == 53) {
			system("cls");
			std::cout << "Your set : " << set << std::endl;
			std::cout << "Input index: ";
			int index = 0;
			std::cin >> index;
			std::cout << "Num = " << set[index];
			Ent();
		}
		if (m == 54) {
			system("cls");
			if (set_sec == Set())
			{
				size_t N = 0;
				std::cout << "Input N = size of set!\nN = ";
				std::cin >> N;
				set_sec = Set(N);
			}
			std::cout << "Unification = " << set + set_sec << std::endl;
			Ent();
		}
		if (m == 55) {
			system("cls");
			if (set_sec == Set())
			{
				size_t N = 0;
				std::cout << "Input N = size of set!\nN = ";
				std::cin >> N;
				set_sec = Set(N);
			}
			std::cout << "Difference = " << set - set_sec << std::endl;
			Ent();
		}
		if (m == 56) {
			system("cls");
			if (set_sec == Set())
			{
				size_t N = 0;
				std::cout << "Input N = size of set!\nN = ";
				std::cin >> N;
				set_sec = Set(N);
			}
			std::cout << "Intersection = " << set.intersection(set_sec) << std::endl;
			Ent();
		}
		if (m == 57) {
			system("cls");
			int num = 0;
			std::cout << "Input num to check in set: ";
			std::cin >> num;
			std::cout << "Number contain = " << set.contain_num(num) << std::endl;
			std::cout << set;
			Ent();
		}
		if (m == 81) {
			system("cls");

			int size = 0;
			std::cout << "Input N = ";
			std::cin >> size;

			int* num = new int[size];
			for (int i = 0; i < size; i++)
			{
				std::cout << "Input elem [" << i << "] = ";
				std::cin >> num[i];
			}

			std::cout << "Dublicates " << std::endl;

			int count;
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					count = 0;
					if (i >= j)
						continue;
					if (num[i] == num[j])
					{
						for (int z = 0; z < i; z++)
						{
							if (num[z] == num[i])
							{
								count = 1;
								break;
							}
						}
						if (count == 0)
							std::cout << num[i] << " ";
						break;
					}
				}
			}
			delete[] num;
			Ent();
		}
		if (m == 87)
		{
			system("cls");
			if (set_sec == Set())
			{
				size_t N = 0;
				std::cout << "Input N = size of second set!\nN = ";
				std::cin >> N;
				set_sec = Set(N);
			}
			if (set == set_sec) std::cout << "Sets are equal" << std::endl;
			else std::cout << "Sets aren't equal" << std::endl;
			std::cin.get();
			std::cin.get();
		}
		if (m == 48) break;
	}
}


int main()
{
	try
	{
		Menu();
	}

	catch (std::exception& ex)
	{
		std::cout << ex.what();
	}
}