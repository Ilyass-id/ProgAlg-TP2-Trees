#include "inttree.h"

//Reponse aux questions
// 2.1 : Depth first search: parcours en profondeur d'abord

int main()
{
    /*
    IntTree* root = new IntTree(12);
    root->addAsLastSon(new IntTree(8));
    root->getSon(0)->addAsLastSon(new IntTree(4));
    root->getSon(0)->addAsLastSon(new IntTree(9));
    root->addAsLastSon(new IntTree(23));
    root->getSon(1)->addAsLastSon(new IntTree(17));
    root->getSon(1)->getSon(0)->addAsLastSon(new IntTree(15));
    root->display("* ");
    delete root;
    */

    //3.1.a. Detecter si le joueur tente de mettre une valeur non entiere dans un noeud

    /*
    double n=10;
    IntTree* root1;


    try{
        root1 = new IntTree(n);
        string str1(typeid(n).name());
        string str2("i");
        if(str1 != str2) throw 10;
    } catch (int e) {
        cerr<<"il y a un souci"<<endl;
    }
    delete root1;
    */
    // 3.1.b. Overflow : Setson : Verification que le message d'erreur fonctionne pour la gestion d'acces aux elements vecteur


    int n2=10;
    IntTree* root2 = new IntTree(n2);
    root2->setSon(2,new IntTree(14));
    delete root2;


    // 3.1.c. Cas où removelastson : pas d'autres sons a enlever (Underflow)

    /*
    int n3=10;
    IntTree* root3 = new IntTree(n3);
    try {
        root3->removeLastSon();
    }  catch(exception const& e) //On rattrape les exceptions standard de tous types
    {
        cerr << "ERREUR : " << e.what() << endl; //On affiche la description de l'erreur
    }
    delete root3;
    */

    // 3.1.d. Cas où getson retourne pointeur nul

    /*
    int n4=10;
    IntTree* root4 = new IntTree(n4);
    root4->addAsLastSon(new IntTree(5));
    try {
        root4->getSon(2);
    }  catch (exception const& e) {
        cerr << "ERREUR : " << e.what() << endl;
    }
    delete root4;
    */

    // 3.1.e. Cas où getdata retourne pas d'entier

    /*
    IntTree* root5;
    int d;
    //root5 = new IntTree(2);   //Si vous voulez essayer sans erreur
    try {
        d = root5->getData();
    }  catch (exception const& e) {
        cerr << "ERREUR : " << e.what() << endl;
    }
    delete root5;
    */


    return 0;
}



