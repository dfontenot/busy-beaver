#ifndef TAPE_DEQUE_H
#define TAPE_DEQUE_H

#include <string>

struct node_t
{
    bool value;
    node_t* left;
    node_t* right;
    
    node_t(bool v, node_t* l, node_t* r) :
        value(v),
        left(l),
        right(r) {}
};

class TapeDeque
{
    public:
    TapeDeque();
    ~TapeDeque();
    node_t* h() const;
    node_t* getPosition() const;
    void moveRight(bool write);
    void moveLeft(bool write);
    bool currentValue() const;
    int score() const;
    std::string str() const;
    
    private:
    node_t* head;
    node_t* currentPosition;
};

#endif
