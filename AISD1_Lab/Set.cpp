#include "Set.h"
#include "math.h"

Set::Set(size_t count)
{
    arr = new int[count];
    size = count;
    size_t i = 0;
    do
    {
        int add_elem;
        std::cout << "Input uniq elem for array: ";
        std::cin >> add_elem;
        if (!contain_num(add_elem))
        {
            arr[i] = add_elem;
            i++;
        }
        else
            std::cout << "This num contain in array" << std::endl;
    } while (i < size);

}

Set::Set(const Set& set)
{
    size = set.size;
    arr = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = set.arr[i];
    }
}

Set::~Set()
{
    delete[]arr;
    size = 0;
}

size_t Set::get_size()
{
    return size;
}

Set Set::operator+(const Set& set)
{
    int* ret_arr = new int[set.size + size];
    int size_arr = 0;

    for (size_t first = 0; first < size; first++, size_arr++) {
        ret_arr[size_arr] = arr[first];
        std::cout << "   " << ret_arr[size_arr];
    }
    for (size_t sec = 0; sec < set.size; sec++, size_arr++)
    {
        if (!contain_num(set.arr[sec])) {
            std::cout << "   " << ret_arr[size_arr];
        }
    }
    return Set(ret_arr, size_arr);
}


Set Set::operator-(const Set& set)
{
    int* ret_arr = new int[size];
    int size_arr = 0;
    bool flag;
    for (size_t first = 0; first < size; first++)
    {
        flag = true;
        for (size_t sec = 0; sec < set.size; sec++)
        {
            if (arr[first] == set.arr[sec])
                flag = false;
        }
        if (flag)
            ret_arr[size_arr++] = arr[first];
    }
    return Set(ret_arr, size_arr);
}



void Set::operator+(const int add_num)
{
    if (contain_num(add_num))
    {
        std::cout << "Collections already have this num";
        return;
    }
    size++;
    int* new_arr = new int[size];
    for (size_t i = 0; i < size - 1; i++)
    {
        new_arr[i] = arr[i];
    }
    new_arr[size - 1] = add_num;
    if (arr != nullptr)
        delete[] arr;
    arr = new_arr;
}


Set& Set::operator+=(const int add_num)
{
    if (contain_num(add_num))
    {
        std::cout << "Collections already have this num";
    }
    else
    {
        size++;
        int* new_arr = new int[size];
        for (size_t i = 0; i < size - 1; i++)
        {
            new_arr[i] = arr[i];
        }
        new_arr[size - 1] = add_num;
        if (arr != nullptr)
            delete[] arr;
        arr = new_arr;
    }
    return *this;
}

void Set::operator-(const int del_num)
{
    if (!contain_num(del_num))
        throw std::logic_error("Delete non-exist element");
    for (size_t i = 0; i < size - 1; i++)
    {
        if (arr[i] == del_num)
        {
            for (; i < size - 1; i++)
                arr[i] = arr[i + 1];
            break;
        }
    }
    size--;
}

Set& Set::operator-=(const int del_num)
{
    if (!contain_num(del_num))
        throw std::logic_error("Delete non-exist element");
    for (size_t i = 0; i < size - 1; i++)
    {
        if (arr[i] == del_num)
        {
            for (; i < size - 1; i++)
                arr[i] = arr[i + 1];
            break;
        }
    }
    size--;
    return *this;
}

int& Set::operator[](const size_t index)
{
    if (arr == nullptr)
        throw std::logic_error("Your array is empty");
    if ((index >= size) || (index < 0)) throw std::logic_error("Index is invalid");
    return arr[index];
}

int Set::operator[](const size_t index) const
{
    if (arr == nullptr)
        throw std::logic_error("Your array is empty");
    if ((index >= size) || (index < 0)) throw std::logic_error("Index is invalid");
    return arr[index];
}


bool Set::operator==(const Set& set)
{
    if (size != set.size)
        return false;
    for (size_t i = 0; i < size; i++)
    {
        if (abs(arr[i] - set.arr[i]) > eps)
            return false;
    }
    return true;
}


bool Set::operator!=(const Set& set)
{
    if (size != set.size)
        return true;
    for (size_t i = 0; i < size; i++)
    {
        if (abs(arr[i] - set.arr[i]) > eps)
            return true;
    }
    return false;
}

Set& Set::operator=(const Set& set)
{
    if (this == (&set))
        return *this;
    if (arr)
    {
        delete[] arr;
        arr = nullptr;
        size = 0;
    }
    if (set.arr)
    {
        arr = new int[set.size];
        size = set.size;
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = set.arr[i];
        }
    }
    return *this;
}


Set Set::intersection(const Set& set)
{
    size_t N = 0;
    if (set.size < size)
        N = set.size;
    else
        N = size;
    int* arr_in = new int[N];
    int sz = 0;
    for (size_t i = 0; i < set.size; i++)
    {
        if (contain_num(set.arr[i]))
        {
            arr_in[sz++] = set.arr[i];
        }
    }
    return Set(arr_in, sz);
}


std::ostream& operator<<(std::ostream& s, const Set& set)
{
    if (set.size == 0)
        throw std::logic_error("You don't write empty array");
    s << "(";
    for (size_t i = 0; i < set.size - 1; i++) {
        s << set.arr[i] << ", ";
    }
    s << set.arr[set.size - 1];
    return s << ")";
}




bool Set::contain_num(const int number)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == number)
            return true;
    }
    return false;
}