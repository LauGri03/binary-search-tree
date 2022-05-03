#include <iostream>

namespace bst {

    class node
   {
   private:
       
   public:
        node(int Value);
        ~node();
        int value;
        node *left;
        node *right;  
   };

    class bst
    {
    private:
        node *root;
    public:
        bst();
        ~bst();
        void print();
        void print(node *no,int space);
        node * search(int cible);
        node * search(node *no,int cible);
        node * getParent(node * no);
        void addNode(int leaf);
        void addNode(node *no, int leaf);
        void deleteNode(int leaf);
        void deleteNode(node *toDelete);
        node * inorderSuccess(node *no);
    };
    

   
    
}