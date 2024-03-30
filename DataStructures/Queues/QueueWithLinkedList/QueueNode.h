#ifndef QUEUENODE_H
#define QUEUENODE_H

template <typename T>
class QueueNode
{
    friend class Queue<T>;
public:
    QueueNode(const& data, QueueNode *next = nullptr ): data{data}, next{next}
    {
    }
    QueueNode(QueueNode *next = nullptr ): next{next}
    {
    }
    virtual ~QueueNode();

protected:
    T data;
    QueueNode *next;
};

#endif // QUEUENODE_H
