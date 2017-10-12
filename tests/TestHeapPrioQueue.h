/*
 * File:   TestHeapPrioQueue.h
 * Author: aaugustyniak
 *
 * Created on 2014-08-16, 13:36:19
 */

#ifndef TESTHEAPPRIOQUEUE_H
#define	TESTHEAPPRIOQUEUE_H

#include <cppunit/extensions/HelperMacros.h>
#include "../HeapPrioQueue.h"

class TestHeapPrioQueue : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TestHeapPrioQueue);
    CPPUNIT_TEST(dequeueMaxTest);
    CPPUNIT_TEST(dequeueMinTest);
    CPPUNIT_TEST(ordQueueTest);
    


    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

private:
    HeapPrioQueue<int> *heapPrioQueue;
    std::vector<int> input;
    int n;
    void dequeueMaxTest();
    void dequeueMinTest();
    void ordQueueTest();
    
};

#endif	/* TESTHEAPPRIOQUEUE_H */

