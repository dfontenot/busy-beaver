#include "TapeDeque.hpp"

#include <cstddef>		// for NULL
#include <cstdlib>
#include <string>
#include <sstream>

TapeDeque::TapeDeque()
{
    head = new node_t(false, NULL, NULL);
    currentPosition = head;
}

TapeDeque::~TapeDeque()
{
    // TODO: make this less copy-paste somehow
    // (not feeling like writing an iterator, something else instead...)
    node_t* current = head->left;

    while(current != NULL)
    {
        node_t* to_delete = current;
        current = current->left;
        free(to_delete);
    }

    current = head->right;
    while(current != NULL)
    {
        node_t* to_delete = current;
        current = current->right;
        free(to_delete);
    }

    free(head);
}

node_t* TapeDeque::h() const
{
    return head;
}

std::string TapeDeque::str() const
{
    std::stringstream ss;

    // seek to far left
    node_t* pos = head;
    while (pos->left != NULL)
    {
        pos = pos->left;
    }

    while (pos != NULL)
    {
        if (pos == currentPosition)
        {
            ss << "[" << pos->value << "]";
        }
        else {
            ss << pos->value;
        }

        pos = pos->right;
    }

    return ss.str();
}

node_t* TapeDeque::getPosition() const
{
    return currentPosition;
}

//return the score (or how many ones are written)
int TapeDeque::score() const
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
    currentPosition->value = write;
    
    //create new node if true, else overwrite
    if(currentPosition->right == NULL)
        currentPosition->right = new node_t(false, currentPosition, NULL);
    
    currentPosition = currentPosition->right;
}

void TapeDeque::moveLeft(bool write)
{
    currentPosition->value = write;
    
    //create new node if true, else overwrite
    if(currentPosition->left == NULL)
        currentPosition->left = new node_t(false, NULL, currentPosition);
    
    currentPosition = currentPosition->left;
}

bool TapeDeque::currentValue() const
{
    return currentPosition->value;
}
