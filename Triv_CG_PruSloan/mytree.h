#ifndef MYTREE_
#define MYTREE_
#include "bnode.h"
#include<iostream>

template <class T>
class mytree{
 private:
   bnode<T>* mangrove[16];
   int size;
   long int found;
   long int missing;
   bool find(T item, bnode<T> *t, int tempticker);
   void insert(T item, bnode<T> *&t);
   
////////////////////////////////////////////////////////////////////////////// 
public:
    mytree()//will set up every entry in mangrove to have a starting point but keeps track of nodes for all of them
    {
        for(int i=0; i<16; i++)
        {
            mangrove[i] = nullptr;
        } 
        size=0;  
        found=0; 
        missing=0;
    } 
    ~mytree()//clear every entry in the mangrove
    {
        for(int i=0; i<16; i++)
        {
            clear(mangrove[i]);
        }
    };
    void insert (T newthing, int arrayspot);
    void remove(T toss, bnode<T> *&t);
    void clear(bnode<T> * t);
    bool find(T item, int arrayspot);
    bool isEmpty() {return size==0;}
    int getSize() { return size;}
    long int getfound() {return found;}
    long int getmissing() {return missing;}
    bnode<T>* findMin (bnode<T> *t);
};

template <class T>
void mytree<T>::insert(T newthing, int arrayspot)//public insert. this is what will be used to access the actual insert via .cpp file
{
    size++;
    if (arrayspot>15)
    {
        return insert(newthing, mangrove[15]);
    }
    else
    {
        return insert(newthing, mangrove[arrayspot-1]);
    }
}

template <class T>
void mytree<T>::insert (T item, bnode<T> *&t)//private insert. this will be putting nodes onto various roots
{
    if (t == nullptr)
        {
            t = new bnode<T>(item);
        }
    else if (item.compare(t -> data)<0)
        {insert(item, t -> left);}
    else if(item.compare(t -> data)>0)
        {insert(item, t -> right);}
}

template <class T>
void mytree<T>::remove(T toss, bnode<T> *&t) //remove a node
{
    if ( t == nullptr) 
    {
        return;
    }   
    if (toss.compare(t->data)<0)
    {
        remove( toss, t->left );
    }
    else if(toss.compare(t->data)>0)
    {
        remove( toss, t -> right );
    }
    else 
    {
        bnode<T> * oldNode;
        if ( t -> left == nullptr) 
        { 
            oldNode = t;
            t = t->right;
            delete oldNode;
            size--;
            return;
         } 
        else if( t -> right == nullptr) 
        { 
            oldNode = t;
            t = t->left;
            delete oldNode;
            size--;
            return;
        }
        oldNode = findMin( t -> right );
        t->data = oldNode->data;
        remove( t -> data, t ->right );
    }
}

template <class T>
bool mytree<T>::find(T newthing, int arrayspot)//public find.this is what will be used to access the actual find via .cpp file
{
    if (arrayspot>15)
    {
        return find(newthing, mangrove[15], 0);
    }
    else
    {
        return find(newthing, mangrove[arrayspot-1], 0);
    }
}

template<class T>
bool  mytree<T>::find(T item, bnode<T>* t, int tempticker)//private find. this will do the actual searching
{
    
    if ( t == nullptr )
        {
            missing+=tempticker;
            return false;
        }
    else if ( item.compare(t -> data)<=-1 )
        {
            tempticker++;
            return find( item, t -> left, tempticker);}
    else if ( item.compare(t -> data)>=1 )
        {
            tempticker++;
            return find( item, t -> right, tempticker);}
    else
        {
            found+=tempticker;
            //std::cout<<tempticker<<"\t"<<found<<"\n"; 
            return true;
        }
}
template<class T>
void mytree<T>::clear(bnode<T>* t) //erase everything in a tree
{
    if (t == nullptr)
          return;
  else {
    clear(t->left);
    clear(t->right);
    delete(t);
  }
}
template<class T>
bnode<T>* mytree<T>::findMin (bnode<T> *t) //find the left most node for each root
{
      if ( t == nullptr )
            return nullptr;
      else if ( t -> left == nullptr )
            return t;
      return findMin (t -> left);
}

#endif
