#include "bst.h"
#define COUNT 10


bst::bst::bst(){
    root = nullptr;
}


bst::bst::~bst(){}

void bst::bst::print(){
    print(root, 0);
}

void bst::bst::print(node *no, int space){
        // Base case
    if (no == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    if(no->right != nullptr){
        print(no->right, space);
    }
 
    // Print current node after space
    // count
    std::cout<<std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout<<" ";
    std::cout<<no->value<<"\n";
 
    // Process left child
    if(no->left != nullptr){
        print(no->left, space);
    }
}


bst::node * bst::bst::search(int cible){ //search with only an int for user utilisation
    return search(root, cible);
}

bst::node * bst::bst::search(node *no, int cible){
    if(no != nullptr){
        if(no->value == cible)
        {
            return no;  //identified node return
        }
        else if((no->value > cible) && (no->left != nullptr) ){
            return search(no->left,cible); //left if greater
        }
        else if((no->value < cible) && (no->right != nullptr) ){
            return search(no -> right,cible); //right if lower
        }
    }
    return NULL;
}

void bst::bst::addNode(int leaf){ //add with only int for user utilisation
    addNode(root,leaf);
}

void bst::bst::addNode(node *no, int leaf){
    if(root == nullptr){
        root = new node(leaf);
    }
    else{
        if((no->value > leaf)){
            if(no->left == nullptr){
                node *ok= new node(leaf);
                no->left = ok;
            }
            else{
                addNode(no->left, leaf);
            }
        }
        else{
            if(no->right == nullptr){
                node *ok= new node(leaf);
                no->right = ok;
            }
            else{
                addNode(no->right, leaf);
            }
        }
    }
}

void bst::bst::deleteNode(int leaf){
    node *toDelete = search(leaf);
    deleteNode(toDelete);
}

void bst::bst::deleteNode(node *cible){
    node *parent = root;

    if(cible != root){
        while((cible != parent->left) && (cible != parent->right)){
            if(cible->value > parent->value){   //Node search + parent identification
                parent = parent->right;
            }
            else if(cible->value < parent->value){
                parent = parent->left;
            }
            else if (cible->value == parent->value){
                parent = parent->right; //case when the deleted node is root
            }
            
        }
    }

    if(cible->left == nullptr && cible->right == nullptr){
        if(cible == parent->right){
            parent->right = nullptr;
        }
        else if(cible == parent->left){
            parent->left = nullptr;
        }
        delete (cible);
    }
    else if(cible->left != nullptr && cible->right != nullptr){
        node *successor = inorderSuccess(cible);
        cible->value = successor->value;
        deleteNode(successor); 
    }
    else{
        if(cible->left != nullptr){
            cible->value = cible->left->value;
            deleteNode(cible->left);
        }
        else{
            cible->value = cible->right->value;
            deleteNode(cible->right);
        }
    }

    
}

bst::node * bst::bst::inorderSuccess(node *no){//find lowest node after a given node
    node *successor = no->right; 

   while(successor->left != nullptr){
       successor = successor->left;
   }
   return successor;

}


bst::node::node(int Value){
    this->value = Value;
    this->left = nullptr;
    this->right = nullptr;
}

bst::node::~node(){}




