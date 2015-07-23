#ifndef LIST
#define LIST
#include "node.cpp"

template <class T>
class List2
{
private:
  Node<T> * liga_;
  size_t lon_;
  void init();
public:
  List2();
  ~List2();
  bool isEmpty ();
  size_t length ();
  void insertAfter (T e);
  void insert (size_t pos,T e);
  T searchPos (size_t pos);
  void modify (size_t pos, T e);
  void erase (size_t pos);
  void copy(List2<T> &lNew);
  void copySorted(List2<T> &lNew);
  /**
   * @brief sort insertion sort
   */
  void sort();
  void sortDesc();
  // Dependientes del elemento
  void insertSorted(T e);
  size_t searchEleName (T e);
  bool readFromFile(const char * fileName);
  bool writeToFile(const char * fileName);
  bool readFromBinaryFile(const char * fileName);
  bool writeToBinaryFile(const char * fileName);
  bool readFromBinaryFile2(const char * fileName);
  bool writeToBinaryFile2(const char * fileName);
  //std::string toStd ();
  //bool readFromFile(const std::string  fileName);
  //bool writeToFile(const std::string fileName);
};
#endif // LIST

