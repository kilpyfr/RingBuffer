
#ifndef SIMPLERING_RINGBUFFER_H
#define SIMPLERING_RINGBUFFER_H
#include <cstddef>


#endif //SIMPLERING_RINGBUFFER_H
typedef std::size_t size_t;

template <typename T, size_t CAPACITY>
struct  RingBuffer {
public:
    RingBuffer(): _head(0), _size(0){};
    bool push(T &value);
    T* getNewest();
   T* getOldest();
    T* getAt(size_t index);
    size_t size() {return _size;}

private:
    size_t _head;
    size_t _size;
    T buffer[CAPACITY];
};

template<typename T, size_t CAPACITY>
bool RingBuffer<T, CAPACITY>::push(T &value) {
    _head = (_head %  CAPACITY) + 1;
    buffer[_head] = value;
    if (_size < CAPACITY) {
        _size++;
    }
    return true;
}
template<typename T, size_t CAPACITY>
T* RingBuffer<T, CAPACITY>::getNewest() {


    return &buffer[_head];
}
template<typename T, size_t CAPACITY>
T* RingBuffer<T, CAPACITY>::getOldest() {


    return &buffer[((_head - _size) %  CAPACITY) + 1];
}
template<typename T, size_t CAPACITY>
T* RingBuffer<T, CAPACITY>::getAt(size_t index) {


    return &buffer[index];
}
