#ifndef BNODE_
#define BNODE_
template<class T> 
class bnode 
{
  public:
  T data;
  bnode<T> * right;
  bnode<T>* left;
  bnode() 
  { 
    right = nullptr;
    left = nullptr;

  }
  bnode(T item) 
  {
      data = item;
      right = nullptr;
      left = nullptr;
  }
};
#endif
