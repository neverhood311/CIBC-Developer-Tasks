#pragma once

template<class T> class CircularArray;	//forward declaration of CircularArray

template <class T>
class CircularArrayIter {
public:
	CircularArrayIter<T>(const CircularArray<T>* _t_arr, int _pos) {
		m_pos = _pos;
		m_p_arr = _t_arr;
	}

	bool operator!= (const CircularArrayIter<T> &_other) const {
		return m_pos != _other.m_pos;
	}

	T operator* () const; 

	const CircularArrayIter<T>& operator++() {
		++m_pos;
		return *this;
	}

private:
	int m_pos;
	const CircularArray<T> *m_p_arr;
};

template <class T>
class CircularArray {
private:
	T *m_array;				//array elements
	unsigned int m_start;	//start position
	unsigned int m_size;	//array size

	unsigned int abs_idx(int _idx) const {
		return (_idx + m_start) % m_size;
	}

public:
	CircularArray(unsigned int _size) : m_size(_size), m_start(0) {
		//allocate space for the array
		m_array = new T[_size];
	}
	
	~CircularArray() {
		//delete the array
		delete[] m_array;
	}

	void rotate(int _offset) {
		//move the start position by _offset, taking care to wrap around
		m_start += _offset;
		m_start = m_start % m_size;
	}

	T& operator[](int _idx) {
		unsigned int idx = this->abs_idx(_idx);
		return m_array[idx];
	}

	T get(int _idx) const {
		//convert _idx into the absolute index for the array
		unsigned int idx = abs_idx(_idx);
		return m_array[idx];
	}

	CircularArrayIter<T> begin() const {
		return CircularArrayIter<T>(this, 0);
	}

	CircularArrayIter<T> end() const {
		return CircularArrayIter<T>(this, m_size);
	}

	void set(int _idx, T _val){
		//convert _idx into the absolute index for the array
		unsigned int idx = this->abs_idx(_idx);
		m_array[idx] = _val;
	}
};

template <class T>
T CircularArrayIter<T>::operator*() const{
	return m_p_arr->get(m_pos);
}
