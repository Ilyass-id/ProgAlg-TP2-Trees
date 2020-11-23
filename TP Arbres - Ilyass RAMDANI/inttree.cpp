#include "inttree.h"


///< Create a node with given information

IntTree::IntTree(int d){
    cout<<"constructeur"<<endl;
    data = d;
}

//Definition du destructeur de maniere recursive
//Question : j'ai n constructions, n-1 destructions car à la non destruction du premier noeud?
IntTree::~IntTree(){
    cout<<"Destruction"<<endl;
    for(int i = 0; i<nbSons(); i++){
        delete sons[i];
    }
}


///< Return information of this node
int IntTree::getData() const{
    if (data>INT8_MAX) throw out_of_range("Vous n'avez pas attribue de valeur initiale a votre IntTree");
    else return data;
}

void IntTree::setData(int d){///< Set information of this node
    cout<<"constructeur"<<endl;
    data = d;
}

int IntTree::nbSons() const{///< Return the number of sons of this node
    return sons.size();
}

void IntTree::setSon(int pos, IntTree* newSon){///< Replace son at pos with newSon
    //3.1.b. risque d'overflow dans le vecteur : directement géré par le vecteur qui est alloue de l'espace dynamiquement
    try {
        sons.at(pos) = newSon;
    }  catch (out_of_range &exn) {
        cerr<< "Out of range: "
            << exn.what()<< endl;
            exit(errno);
    }
    sons[pos] = newSon;
}

///< Son at pos (left-most son at position 0)
IntTree* IntTree::getSon(int pos){
    if (pos>=int(sons.size())) throw out_of_range("Il n'y a pas de son a cette position, vous allez trop loin!");
    else return sons[pos];
}


///< See non-const overload
const IntTree* IntTree::getSon(int pos) const{
    if (pos>=int(sons.size())) throw out_of_range("Il n'y a pas de son a cette position, vous allez trop loin!");
    else return sons[pos];
}


///< Add newSon as right-most son
void IntTree::addAsLastSon(IntTree* newSon){
    //Erreur pouvant rendre cyclique l'arbre : qu'un son apparraisse plusieures fois dans l'arbre.
    // Il faut creer operateur = operateur copie
    sons.push_back(newSon);                // ajoute a la fin de la liste (DOCU vector)
}

///< Remove right-most son of this node
void IntTree::removeLastSon(){
    //3.1.c. Risque d'underflow dans le vecteur : directement géré par le vecteur
    if (sons.size()==0) throw underflow_error("Le vecteur est vide, il n'y a plus d'elements a enlever");
    else sons.pop_back();                       // retire le dernier element (DOCU)
}

///< Méthode recursive qui affiche l'arbre en DFS
void IntTree::display(string prefix, string indent){
    cout<<prefix;
    cout<<indent;
    cout<<data<<endl;
    indent+="   ";      // Nous voulons différencier les enfants pour chaque profondeur donc nous ajoutons un indent
    for(int i = 0; i<nbSons(); i++){
        sons[i]->display(prefix, indent);
    }
}
