#include "TapeDeque.hpp"

#include <cstddef>		// for NULL

TapeDeque::TapeDeque()
{
    head = new node_t(false, NULL, NULL);
    currentPosition = head;
}

TapeDeque::~TapeDeque() {}

node_t* TapeDeque::h()
{
    return head;
}

node_t* TapeDeque::getPosition()
{
    return currentPosition;
}

//return the score (or how many ones are written)
int TapeDeque::score()
{
    //go all the way to the left and count upwards
    node_t* current = head;
    int score = 0;

    // check head
    if(current->value)
	score++;

    // look to the left all the way
    while(current->left != NULL)
    {
	if(current->left->value)
	    score++;
	
        current = current->left;
    }

    current = head;

    // look to the right all the way
    while(current->right != NULL)
    {
        if(current->right->value)
	    score++;
	
        current = current->right;
    }
    
    return score;
}

void TapeDeque::moveRight(bool write)
{
    //create new node if true, else overwrite
    if(currentPosition->right == NULL)
        currentPosition->right = new node_t(write, currentPosition, NULL);
    else
        currentPosition->right->value = write;
    
    currentPosition = currentPosition->right;
}

void TapeDeque::moveLeft(bool write)
{
    //create new node if true, else overwrite
    if(currentPosition->left == NULL)
        currentPosition->left = new node_t(write, NULL, currentPosition);
    else
        currentPosition->left->value = write;
    
    currentPosition = currentPosition->left;
}

bool TapeDeque::currentValue()
{
    return currentPosition->value;
}
