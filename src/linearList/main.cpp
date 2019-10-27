#include <iostream>

using namespace std;

// template <class T>
// ostream & operator<< (ostream&out, LinearList<T> &list);

template <class T>
class LinearList {
  private:
    T* element;
    int size;
    int len;
  public:
    LinearList(int size=4);
    LinearList(T value[], int n);
    ~LinearList();
    bool isEmpty();
    int length();
    T get(int i);
    bool set(int i, T x);
    template <class Ty>
    friend ostream &operator<<(ostream &out, LinearList<Ty>&list);
    bool insert(int i, T x);
    bool remove(int i, T &old_x);
    void clear();
    void print();
    int get_size();
};

template<class T>
LinearList<T>::LinearList(int size) {
  this->size = 4 < size ? size : 4;
  this->element = new T[this->size];
  this->len = 0;
}

template <class T>
LinearList<T>::LinearList(T value[], int n) {
  if (n > 0) {
    this->size = 2*n;
    this->element = new T[this->size];
    for (int i = 0; i < n; ++i) {
      this->element[i] = value[i];
    }
    this->len = n;
  }
}

template <class T>
bool LinearList<T>::isEmpty()
{
  return this->len == 0;
}

template <class T>
LinearList<T>::~LinearList() {
  delete[] this->element;
}

template <class T>
int LinearList<T>::length() {
  return this->len;
}

template <class T>
T LinearList<T>::get(int i) {
  if (i >= 0 && i < this->len) {
    return this->element[i];
  }
}

template <class T>
bool LinearList<T>::set(int i, T x) {
  if(i < len && i > 0) {
    element[i] = x;
    return true;
  } else {
    return false;
  }
}

template <class T>
bool LinearList<T>::insert(int i, T x) {
  if(i >= 0&& i <= len) {
    if (len == size) {
      // int n = this->size + 4;
      this->size = this->size + 4;
      T *tmp = new T[this->size];
      for(int j = 0; j < this->len; ++ j) {
        tmp[j] = element[j];
      }
      delete[] element;
      element = tmp;
    }
    for(int j = len; j > i; --j) {
      element[j] = element[j-1];
    }
    element[i] = x;
    len++;
    return true;
  } else {
    return false;
  }
}

template <class T>
bool LinearList<T>::remove(int i, T &old_x) {
  if(i < 0 && i >= len) {
    return false;
  } else {
    old_x = element[i];
    for (int j = i; j < len; ++j) {
      element[j] = element[j+1];
    }
    --len;
    return true;
  }
}

template<class T>
void LinearList<T>::clear() {
  len = 0;
  delete[] element;
  size = 4;
  element = new T[this->size];
}

template <class T>
void LinearList<T>::print() {
  for (int i = 0;i < len; ++i) {
    cout << element[i] << " ";
  }
  cout << endl;
}

template <class T>
int LinearList<T>::get_size() {
  return size;
}

template <class T>
ostream &operator<<(ostream&out, LinearList<T> &list) {
  out << "(";
  if (list.len > 0) {
    out << list.element[0];
    for(int i = 1; i <list.len; ++i) {
      out << "," << list.element[i];
    }
  }
  out << ")\n";
  return out;
}

int main()
{
    LinearList<int> a(3);
    a.insert(0,1);
    a.insert(0, 2);
    for (int i = 0; i < 4; ++i) {
      a.insert(0,i+3);
    }
    int x;
    cout << a;
    cout << "a length is:" << a.length() << endl;
    cout << "a size is:" << a.get_size() << endl;
    a.remove(0,x);
    cout << a;
    cout << "a length is:" << a.length() << endl;
    cout << "a size is:" << a.get_size() << endl;
    // cout << a << endl;
    // cout << "Hello LeetCode!!!" << endl;
    a.clear();
    cout << "a length is:" << a.length() << endl;
    cout << "a size is:" << a.get_size() << endl;
    cout << a.isEmpty() << endl;
    return 0;
}
