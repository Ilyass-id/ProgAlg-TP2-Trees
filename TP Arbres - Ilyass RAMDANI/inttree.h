#pragma once
#include <vector>
#include <iostream>
#include <typeinfo>
#include <cassert>
#include <cerrno>
using namespace std;

/// 3.1) Type d'erreurs
/// a. Que le joueur tente de mettre une valeur non entiere dans un noeud
/// b. Overflow dans le vecteur : directement géré par le vecteur qui est alloue de l'espace dynamiquement
/// c. removelastson : pas d'autres sons a enlever (Underflow)
/// d. getson pointeur nul retourner pointeur nul
/// e. get data : entier nul
///

class IntTree {
    int data; ///< Node information
    vector<IntTree*> sons; ///< Sequence of sons (empty if none)
public:
    IntTree(int d); ///< Create a node with given information
    ~IntTree();     ///< Destruct a node and all its descendants

    int getData() const; ///< Return information of this node
    void setData(int d); ///< Set information of this node
    //Actions with sons
    int nbSons() const; ///< Return the number of sons of this node

    void setSon(int pos, IntTree* newSon); ///< Replace son at pos with newSon
    IntTree* getSon(int pos); ///< Son at pos (left-most son at position 0)
    const IntTree* getSon(int pos) const; ///< See non-const overload

    void addAsLastSon(IntTree* newSon); ///< Add newSon as right-most son
    void removeLastSon(); ///< Remove right-most son of this node

    void display(string prefix = "", string indent = " "); ///< Méthode recursive qui affiche l'arbre en DFS
};
