#ifndef _PTR_VECTOR_H_
#define _PTR_VECTOR_H_

#include <vector>

template<typename T>
class ptr_vector : public std::vector<T*>
{
public:
	~ptr_vector()
	{
		clear();
	}

	void clear()
	{
		std::vector<T*>::iterator it;
		for (it = begin(); it != end(); ++it)
			delete *it;
		std::vector<T*>::clear();
	}


	void push_back(T* const &val)
	{
		std::auto_ptr<T> ptr(val);
		std::vector<T*>::push_back(val);
		ptr.release();
	}

	void push_back(std::auto_ptr<T>& val)
	{
		std::vector<T*>::push_back(val.get());
		val.release();
	}
};


#endif //_PTR_VECTOR_H_