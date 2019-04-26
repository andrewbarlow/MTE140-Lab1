// .cpp files contain code definitions for methods that have been declared
// in the according .hpp file. The skeleton has been set up here for you.
// That is, the methods have been initiated, and your mission, should you
// choose to accept it (which you should for marks), is to fill in each method
// with the appropriate code.
//
// A note about the "::" syntax: generally, this means "the thing on the right
// belongs to the thing on the left." So, SequentialList::empty() means the method
// empty() belongs to the class SequentialList. This allows empty() to access (and
// potentially change) the member variables in class SequentialList.

#include "SequentialList.hpp"
#include <iostream>
#include <string>

using namespace std;

// This is the constructor.
SequentialList::SequentialList(unsigned cap)
{
    capacity_ = cap;
    size_ = 0;
    data_ = new DataType[cap];
}

SequentialList::~SequentialList()
{
    delete [] data_;
}

bool SequentialList::empty() const
{
    return size_ == 0;
}

unsigned SequentialList::size() const
{
    return size_;
}

unsigned SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::full() const
{
    return size_ == capacity_;
}

void SequentialList::print() const
{
    for(unsigned i = 0; i < size_; i++)
        cout << data_[i] << endl;
}

// NOTE on inserts: do NOT grow the array if we reach capacity. Simply return false.
bool SequentialList::insert_front(DataType val)
{
    if (size_ == capacity_)
        return false;
    size_++;
    for(int i = size_ + 1; i > 0; i--)
    {
        data_[i] = data_[i - 1];
    }
    data_[0] = val;
    return true;
}

bool SequentialList::remove_front()
{
	if(size_ == 0)
		return false;
    data_[0] = 0;
    for(unsigned i = 1; i < size_; i++)
    {
        data_[i - 1] = data_[i];
    }
    size_--;
    return true;
}

bool SequentialList::insert_back(DataType val)
{
	if (size_ == capacity_)
		return false;
	size_++;
    data_[size_ - 1] = val;
    return true;
}

bool SequentialList::remove_back()
{
	if(size_ == 0)
		return false;
	data_[size_ - 1] = 0;
	size_--;
	return true;
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if (size_ == capacity_)
        return false;
    size_++;
    for(unsigned i = index; i < size_; i++)
     {
    	int swap = data_[i + 1];
    	data_[i + 1] = data_[i];
    	data_[i + 2] = swap;
     }
    data_[index] = val;
    return true;
}

bool SequentialList::remove(unsigned int index)
{
	if(size_ == 0)
		return false;
    for(unsigned i = index; i < size_; i++)
    {
    	int swap = data_[i + 1];
    	data_[i + 1] = data_[i];
    	data_[i] = swap;
    }
    data_[index] = 0;
    size_--;
    return true;
}

unsigned SequentialList::search(DataType val) const
{
    for(unsigned i = 0; i < size_; i++)
        if(data_[i] == val)
            return i;
    return size_;
}

SequentialList::DataType SequentialList::select(unsigned index) const
{
	if(index < size_)
		return data_[index];
	else
		return data_[size_ - 1];
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    data_[index] = val;
    return true;
}
