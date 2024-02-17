#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <vector>

#include "queue.hpp"

template <typename T> class Dequeue : public Queue<T>
{
  public:
    // Inherit the constructors of Queue<T>
    using Queue<T>::Queue;

    // Access the element at the back of the queue
    T &back()
    {
        // _position is the predecessor to the back so add 1 to get the back
        return this->_storage[this->_position + 1];
    }

    // Const-access the element at the back of the queue
    const T &back() const
    {
        return this->_storage[this->_position + 1];
    }

    // Add a new element to the front of the queue by copying
    void enqueue_front(const T &value)
    {
        // Checking that there is still enough space for elements
        assert(this->_size < this->_storage.size());

        // Increasing the size - moves _head to the right spot
       this->_size++;

        // _head() returns the index of element at the front
        this->_storage[this->_head()] = value;

    }

    // Remove the element at the back of the queue
    void dequeue_back()
    {
        // Checking that there is something to dequeue
        assert(this->_size >= 1);

        // Increase _position by 1 to remove element at back
        this->_position++;

        // Change the size
        this->_size--;

    }

    // Remove all elements from the queue
    void clear() { 
        // As long as there are elements in the queue, remove them
        if (this->_size >= 1){
            this->dequeue();
        }
    }

  protected:
    // Return the index of the element at the back of the queue
    size_t _tail() const
    {
        // Making sure that there is at least 1 element
        assert(this->_size >= 1);

        // _position is the predecessor to the back
        size_t index = this->_position + 1;

        // If the index is out of the _storage vector it is moved to the front
        // Because we are using a ring buffer
        if (index >= this->_storage.size()) { index -= this->_storage.size(); }

        // Index returned
        return index;
    }
};

#endif // __queue_enhanced__