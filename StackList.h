//
//  StackList.h
//

#ifndef StackList_h
#define StackList_h

#include <utility>
#include <iostream>
#include <exception>
namespace asd1 {

  class StackEmptyException { };

  template<typename T>
  class StackList {
  public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;

  private:
    struct Node {
      Node* nxt;
      value_type val;
    };
    Node* topNode;

  public:

// A compléter sans ajouter d'attributs privés et sans utiliser le type T
// autrement que via les types value_type, reference et const_reference
//
// vous devez mettre en oeuvre le constructeur par défaut, le destructeur,
// les méthodes push, pop, top et empty, ainsi que le constructeur de copie
// et l'opérateur d'affectation par copie. Quand c'est pertinent, il faut
// lever l'exception StackEmptyException
//
// Cette classe doit offrir garanties faible et forte pour toutes ses
// fonctionalités

    //Constructeur
    StackList() : topNode(nullptr){}
    //Constructeur par copie
    StackList(const StackList& s){
        //Faire des nouvelles allocations mémoires pour tous les éléments de la liste
        if(!s.empty()){

            Node * top = new Node{nullptr,s.topNode->val};
            Node * currentNode = top;
            Node * nextTop = s.topNode->nxt;
            //Utilisation du try/bloc pour éviter une "fuite de mémoire" en cas d'exception(s)
            try{
                while(nextTop != nullptr){
                    currentNode->nxt = new Node{nullptr,nextTop->val};
                    nextTop = nextTop->nxt;
                    currentNode = currentNode->nxt;
                }
                topNode = top;
            }catch(...){
                delete top;
                delete currentNode;
                throw ;
            }
        }
    }
    //Destructeur
    ~StackList(){
        //On delete tous les items de la stack
        while(!empty()){
            Node * toDelete = topNode;
            topNode = topNode->nxt;
            delete toDelete;
        }
    }
    //Operateur =
    void operator = (const StackList& s){
        //On check si les valeurs sont possible à copier
        try{
            StackList<value_type> tmp = s;
        }catch(...){
            throw;
        }
        //On détruit la liste
        this->StackList::~StackList();
        //On reconstruit la liste via le constructeur par copie
        new(this) StackList<value_type>(s);
    }

    bool empty() const noexcept {
        if(topNode == nullptr)
            return true;
        return false;
    }
    void push(const_reference val){
        Node * n = new Node{topNode,val} ;
        topNode = n;
    }
    void pop(){
        if(empty()){
            throw StackEmptyException();
        }
        Node * toDelete = topNode;
        topNode = topNode->nxt;
        delete toDelete;
    }
    const_reference top() const {
        if(empty()){
            throw StackEmptyException();
        }
        return topNode->val ;
    }

    reference top() {
        if(empty())
            throw StackEmptyException();
        return topNode->val ;
    }
};

}

#endif /* StackList_h */
