#include <iostream>;

3
template<class T>
class TreeIterator
{
public:
  Tree<T>* tree;
  DListIterator<Tree<T>*> sonsItr;

  TreeIterator () : tree(NULL) {}
  TreeIterator (Tree<T>*);

  void Root (); // pereiti v kornevoi yzel
  void Up (); // pereiti na level up
  void Down (); // pereiti na level down
  void CreateSon (); // dobavit yzel v sons
  void NextSon(); // next yzel v sons
  void PreviousSon (); // last yzel v  sons
  void FirstSon (); // first yzel spiska sons
  void LastSon (); // last yzel spiska sons
  void InsertData (T d); // vstavit dannie v tekuchii yzel v  sons
};

TreeIterator () : tree(NULL) {}

template<class T>
TreeIterator<T>::TreeIterator (Tree<T>* t)
{
  tree = t; // tekuchii yzel
  sonsItr.node = tree->sons.head; // first yzel spiska sons
  sonsItr.list = &tree->sons;
}
template<class T>
void TreeIterator<T>::Root ()
{
  while (tree->parent != NULL)
    Up();
}

template<class T>
void TreeIterator<T>::Up ()
{
  if (tree->parent != NULL)
  {
    tree = tree->parent;
    sonsItr.node = tree->sons.head;
    sonsItr.list = &tree->sons;
  }
}
template<class T>
void TreeIterator<T>::Down ()
{
  if (sonsItr.node->data != NULL)
  {
    tree = sonsItr.node->data;
    sonsItr.node = tree->sons.head;
    sonsItr.list = &tree->sons;
  }
}

template<class T>
void TreeIterator<T>::CreateSon ()
{
  tree->sons.Insert(sonsItr, new Tree<T>);
  sonsItr.node->data->parent = tree;
}


template<class T>
void TreeIterator<T>::NextSon()
{
  if (sonsItr.node->next != NULL)
  {
    sonsItr.node = sonsItr.node->next;
  }
}

template<class T>
void TreeIterator<T>::PreviousSon ()
{
  if (sonsItr.node->previous != NULL)
    sonsItr.node = sonsItr.node->previous;
}

template<class T>
void TreeIterator<T>::FirstSon ()
{
  sonsItr.Start();
}

template<class T>
void TreeIterator<T>::LastSon ()
{
  sonsItr.End();
}

template<class T>
void TreeIterator<T>::InsertData (T d)
{
  if (sonsItr.node->data != NULL)
    sonsItr.node->data->data = d;
}
