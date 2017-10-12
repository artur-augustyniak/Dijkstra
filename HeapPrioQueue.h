/* 
 * File:   HeapPrioQueue.h
 * Author: aaugustyniak
 *
 * Created on 16 sierpień 2014, 13:34
 */

#ifndef HEAPPRIOQUEUE_H
#define	HEAPPRIOQUEUE_H
#include <vector>
#include<cmath>
#include<climits>
#include <algorithm>

template<class T>
class Rel {
public:

    bool operator()(T* a, T* b) {
        return cmp(a, b);
    }
private:
    virtual bool cmp(T* a, T* b) = 0;
};

template< class T >
class LT : public Rel<T> {
private:

    bool cmp(T* a, T* b) {
        return *a < *b;
    }
};

template<class T>
class GT : public Rel<T> {
private:

    bool cmp(T* a, T* b) {
        return *a > *b;
    }
};

template<class T>
class HeapPrioQueue {
public:

    HeapPrioQueue() {
        initHeapStorage();
    }

    HeapPrioQueue(std::vector<T*> payload) {
        initHeapStorage();
        for (int i = 0; i < payload.size(); i++) {
            heap.push_back(payload[i]);
        }
        applyHeapInvariant(lt);
    }

    HeapPrioQueue(const HeapPrioQueue& orig) {
    }

    virtual ~HeapPrioQueue() {
    }

    void clear() {
        heap.clear();
        initHeapStorage();
        applyHeapInvariant(lt);
    }

    void enqueue(T* item) {
        heap.push_back(item);
    }

    T* dequeue() {
        applyHeapInvariant(lt);
        std::swap(heap[1], heap.back());
        T elem = heap.back();
        heap.pop_back();
        return elem;
    }

    T* dequeueMax() {
        return dequeue();
    }

    T* dequeueMin() {
        applyHeapInvariant(gt);
        std::swap(heap[1], heap.back());
        T* elem = heap.back();
        heap.pop_back();
        return elem;
    }

    T* getMax() {
        applyHeapInvariant(lt);
        return heap[1];
    }

    T* getMin() {
        applyHeapInvariant(lt);
        return heap[1];
    }

    bool isEmpty() {
        return size() == 0;
    }

    int size() {
        return heap.size() - 1;
    }

    std::vector<T*> iterable() {
        std::vector<T*> tmp;
        for (int i = 1; i < heap.size(); i++) {
            tmp.push_back(heap.at(i));
        }
        return tmp;
    }

private:
    std::vector<T*> heap;
    LT<T> lt;
    GT<T> gt;

    void initHeapStorage() {
        heap.push_back(0);
    }

    void applyHeapInvariant(Rel<T>& r) {

        for (int i = 2; i < heap.size(); i++) {
            int currPos = i;
            int currPredcessor = currPos / 2;
            T* tmpVal = heap.at(i);

            while (currPredcessor > 0 && r(heap.at(currPredcessor), tmpVal)) {
                heap[currPos] = heap.at(currPredcessor);
                currPos = currPredcessor;
                currPredcessor = currPos / 2;
            }
            heap[currPos] = tmpVal;

        }
    }
};

#endif	/* HEAPPRIOQUEUE_H */

