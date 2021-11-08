//
//  TreeNode.hpp
//  BinaryTree
//
//  Created by Vicente Cubells on 13/10/20.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <iostream>

template <class T>
class TreeNode {
private:
    T info;
    TreeNode<T> * left = nullptr;
    TreeNode<T> * right = nullptr;
    
    TreeNode<T> * parent = nullptr;
    
    int level = 0;
    
public:
    /* Constructores */
    TreeNode() { };
    TreeNode(const T & _info) : info(_info) {}
    TreeNode(const TreeNode<T> & );
    
    /* Destructor */
    virtual ~TreeNode();
    
    /* Getter y Setter */
    T getInfo() const { return info; }
    void setInfo(T & value) { info = value; }
    
    TreeNode<T> * getLeft() const { return left; }
    void setLeft(TreeNode<T> * value) { left = value; }
    
    TreeNode<T> * getRight() const { return right; }
    void setRight(TreeNode<T> * value) { right = value; }
    
    TreeNode<T> * getParent() const { return parent; }
    void setParent(TreeNode<T> * value) { parent = value; }
    
    int getLevel() const { return level; }
    void setLevel(int value) { level = value; }
    
    /* Sobrecarga operador == */
    bool operator ==(TreeNode<T> &);
    
    /* Sobrecarga operador << */
    template <typename Tn>
    friend std::ostream & operator << (std::ostream & os, const TreeNode<Tn> & node);
};

template <class T>
TreeNode<T>::TreeNode(const TreeNode<T> & other)
{
    info = other.info;
    left = other.left;
    right = other.right;
}

template <class T>
TreeNode<T>::~TreeNode()
{
    info.~T();
    left = nullptr;
    right = nullptr;
}

template <class T>
bool TreeNode<T>::operator ==(TreeNode<T> & other)
{
    return (info == other.info);
}

template <class T>
std::ostream & operator << (std::ostream & os, const TreeNode<T> & node)
{
    os << node.info;
    
    return os;
}

#endif /* TreeNode_hpp */
