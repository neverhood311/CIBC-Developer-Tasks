#pragma once

template<class T> class CircularArray;	//forward declaration of CircularArray

template <class T>
class CircularArrayIter {
public:
	CircularArrayIter<T>(const CircularArray<T>* _t_arr, int _pos) {
		//TODO
	}

	bool operator!= (const CircularArrayIter<T> &_other) {
		return m_pos != other.m_pos;
	}

	//T operator* () const;	//TODO: do we need this?

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
public:
	CircularArray(unsigned int _size);
	~CircularArray();

	void rotate(int _offset);

	T operator[](int _idx) {
		return get(_idx);
	}

	T get(int _idx) {
		unsigned int abs_idx = (_idx + m_start) % m_size;
		return m_array[abs_idx];
	}

	CircularArrayIter<T> begin() const {
		return CircularArrayIter<T>(this, 0);
	}

	CircularArrayIter<T> end() const {
		return CircularArrayIter<T>(this, m_size);
	}

	void set(int _idx, T _val){
		//TODO
	}
};


