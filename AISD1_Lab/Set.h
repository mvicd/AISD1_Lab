#pragma once
#include <iostream>


class Set {
	int* arr;
	size_t size;
	double eps = 0.001;
public:
	Set() : arr(nullptr), size(0) {}
	Set(size_t count);
	Set(int* new_arr, size_t count) : arr(new_arr), size(count) {}
	Set(const Set& set);
	~Set();
	size_t get_size();
	Set operator + (const Set& set);
	Set operator - (const Set& set);

	void operator + (const int add_num);
	Set& operator += (const int add_num);
	void operator - (const int del_num);
	Set& operator -= (const int del_num);

	int& operator [] (const size_t index);
	int operator [] (const size_t index) const;
	bool operator == (const Set& set);
	bool operator != (const Set& set);
	Set& operator = (const Set& set);

	Set intersection(const Set& set);
	bool contain_num(const int number);
	friend std::ostream& operator<< (std::ostream& out, const Set& set);
};

std::ostream& operator<< (std::ostream& out, const Set& set);