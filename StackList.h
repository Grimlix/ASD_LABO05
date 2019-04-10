//
//  StackList.h
//

#ifndef StackList_h
#define StackList_h

#include <utility>

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
    StackList(){
        topNode = nullptr;
    }
    bool empty(){
        if(topNode == nullptr)
            return true;
        return false;
    }
    void push(const_reference val){
        Node n ;
        n.val = val;
        Node* next = topNode;
        topNode = &n;
        (*topNode).nxt = next;
    }
    void pop(){
        topNode = (*topNode).nxt;
    }
    const_reference top() const {
        return (*topNode).val ;
    }
    reference top() {
        return (*topNode).val ;
    }
};

}

#endif /* StackList_h */
