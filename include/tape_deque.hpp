#ifndef TAPE_DEQUE_H
#define TAPE_DEQUE_H

struct node_t
{
    bool value;
    struct node_t* left;
    struct node_t* right;
    
    node_t(bool v, struct node_t* l, struct node_t* r) : value(v), left(l), right(r) {}
};
typedef struct node_t node_t;

class TapeDeque
{
    public:
    TapeDeque();
    ~TapeDeque();
    node_t* h();
    node_t* getPosition();
    void moveRight(bool write);
    void moveLeft(bool write);
    bool currentValue();
    int score();
    
    private:
    node_t* head;
    node_t* currentPosition;
};

#endif
