#ifndef TEST_H
#define TEST_H

#include "Queue.h"
#include <string>
#include <iostream>

class Test {
    private:
        int testCount;
        std::string msg;
        bool passed;
    public:
        Test();
        ~Test();
        void run();
    protected:
        void print_test_status();
        void run_test(bool result, std::string msg);
        bool empty_on_construction();
        bool is_empty(int n);
        bool dequeue_returns_value();
        bool enqueue_dequeue_same_size(int n);
        bool enqueue_peekFront_same_content(int n);
        bool enqueue_peekFront_same_content_stack(int n);
        bool dequeue_runtime_error_on_empty();
        bool peekFront_runtime_error_on_empty();
};


#endif