#include<iostream>
using namespace std;

class set{

struct node{
    node * left, *right, *parent;
    int val;
};
node* head;

public:
set(){
    head->left=head->right=head->parent=head;
}
void insert(const int& vall){
    node* temp;
    temp=new node;
    temp->val=vall;
    if(head->parent==head){
        temp->left=head;
        temp->right=head;
        temp->parent=head->parent;

        head->right=temp;
        head->left=temp;
        head->parent=temp;
    }    

    else{
        node* ptr=head->parent;

        while(1){
            if(temp->val>ptr->val){
                if(ptr->right==head){
                    ptr->right=temp;

                    temp->right=head;
                    temp->left=head;
                    temp->parent=ptr;

                    head->right=temp;
                    break;
                }
                else{
                    ptr=ptr->right;
                }
            }
            else{
                 if(ptr->left==head){
                    ptr->left=temp;

                    temp->right=head;
                    temp->left=head;
                    temp->parent=ptr;

                    head->left=temp;
                    break;
                }
                else{
                    ptr=ptr->left;
                }
            }
        }
    }
}};
int main(){
    set obj;
    obj.insert(3);
    obj.insert(7);
    obj.insert(8);
    obj.insert(2);
}