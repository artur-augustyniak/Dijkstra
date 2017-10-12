/*
 * File:   TestHeapPrioQueue.cpp
 * Author: aaugustyniak
 *
 * Created on 2014-08-16, 13:36:19
 */
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "TestHeapPrioQueue.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestHeapPrioQueue);

void TestHeapPrioQueue::setUp() {
    heapPrioQueue = new HeapPrioQueue<int>();
    n = 1000;
    srand(clock());
    for (int i = 0; i < n; i++) {
        input.push_back(rand());
        heapPrioQueue->enqueue(&input.at(i));
    }
    std::sort(input.begin(), input.end());
}

void TestHeapPrioQueue::tearDown() {
    delete heapPrioQueue;
    input.clear();
}

void TestHeapPrioQueue::dequeueMaxTest() {
    for (int j = 1; j < n; j++) {
        CPPUNIT_ASSERT_EQUAL(&input[input.size() - j],
                heapPrioQueue->dequeueMax());
    }
}

void TestHeapPrioQueue::dequeueMinTest() {
    for (int j = 0; j < n; j++) {
        CPPUNIT_ASSERT_EQUAL(input[j],
                heapPrioQueue->dequeueMin());
    }
}

void TestHeapPrioQueue::ordQueueTest() {
    heapPrioQueue->clear();
    
    heapPrioQueue->enqueue(4);
    heapPrioQueue->enqueue(2);
    heapPrioQueue->enqueue(6);
    CPPUNIT_ASSERT_EQUAL(2, heapPrioQueue->dequeueMin());
    CPPUNIT_ASSERT_EQUAL(4, heapPrioQueue->dequeueMin());

    heapPrioQueue->enqueue(5);
    CPPUNIT_ASSERT_EQUAL(6, heapPrioQueue->dequeueMax());
    CPPUNIT_ASSERT_EQUAL(5, heapPrioQueue->dequeueMax());

    heapPrioQueue->enqueue(1);
    heapPrioQueue->enqueue(2);
    heapPrioQueue->enqueue(3);
    CPPUNIT_ASSERT_EQUAL(3, heapPrioQueue->dequeueMax());
    CPPUNIT_ASSERT_EQUAL(2, heapPrioQueue->dequeueMax());
    CPPUNIT_ASSERT_EQUAL(1, heapPrioQueue->dequeueMax());
}

