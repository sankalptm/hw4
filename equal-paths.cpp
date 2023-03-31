#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
int controlLength(Node* root);
bool pathLength(Node*root, int current, int control); 
bool equalPaths(Node * root)
{
    // Add your code below
    //int count=0;
  int control=controlLength(root);
    //gives control length for comparison
  if (pathLength(root, 0, control)){
      return true;
    }
    else {
      return false;
    }
  /*int left_side= finalResult(root->left)+1;
  int right_side= finalResult(root->right)+1;
  if (left_side==right_side){
    return true;
  }
  else{
    return false;
  }*/



}
//three parameters have a control length as base case

int controlLength(Node* root){
  if (root==NULL){
    return 0;
  }
  else {
    
    return 1+ controlLength(root->left);
  }
}

bool pathLength(Node*root, int current, int control){
  if (root==NULL){
    return true;
  }
  else if(root->left==NULL && root->right==NULL){
    return true;
    
  }

  else {
    current++;
    bool left_side=pathLength(root->left, current, control);
    bool right_side=pathLength(root->right,current, control);
    if (left_side==true && right_side==true){
      return true;
    }
    else {
      return false;
    }
  }

}
/*int finalResult (Node* root){
  if (root==NULL){
    return 1;
  }
  else if(root->left==NULL && root->right==NULL){
    return 1;
    
  }
  else if (root->left ==NULL && root->right!=NULL){
    return -1;
  }
  else if (root->right==NULL && root->left!=NULL){
    return -1;
  }
  finalResult(root->left);
  finalResult(root->right);


}*/







