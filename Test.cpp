#include "Test.h"

Test::Test() {
    this->testCount = 1;
}

Test::~Test() {}

bool Test::empty_on_construction() {
    Queue q;
    if(q.isEmpty()) return true;
    else {
        try {
            q.dequeue();
            return false;
        }
        catch(std::runtime_error& e)
        {
            return true;
        }
    }
}

bool Test::is_empty(int n) {
    Queue q;
    for(int i = 0; i < n; i++) {
        q.enqueue(i);
    }
    if(q.isEmpty()) return true;
    return false;
}

bool Test::dequeue_returns_value() {
    return false;
}

bool Test::enqueue_dequeue_same_size(int n) {
    Queue q;
    for(int i = 0; i < n; i++) {
        q.enqueue(i);
    }

    try {
        for(int i = 0; i < n; i++) {
            q.dequeue();
        }
    }
    catch(std::runtime_error& e) {
        return false;
    }

    if(q.isEmpty()) return true;

    return false;
}

bool Test::enqueue_peekFront_same_content(int n) {
    Queue q;
    for(int i = 0; i < n; i++) {
        q.enqueue(i);
    }
    for(int i = 0; i < n; i++) {
        if(q.peekFront() != i) return false;
        q.dequeue();
    }

    for(int i = 0; i < n; i++) {
        q.enqueue(n-i);
    }
    for(int i = 0; i < n; i++) {
        if(q.peekFront() != (n-i)) return false;
        q.dequeue();
    }
    return true;
}

bool Test::enqueue_peekFront_same_content_stack(int n) {
    Queue q;
    for(int i = 0; i < n; i++) {
        q.enqueue(i);
    }
    for(int i = n-1; i >= 0; i--) {
        if(q.peekFront() != i) return false;
        q.dequeue();
    }

    for(int i = n; i > 0; i--) {
        q.enqueue(i);
    }
    for(int i = 1; i <= n; i++) {
        if(q.peekFront() != i) return false;
        q.dequeue();
    }
    return true;
}

bool Test::dequeue_runtime_error_on_empty() {
    Queue q;
    try {
        q.dequeue();
        return false;
    }
    catch(std::runtime_error& e) {
        return true;
    }
    return false;
}

bool Test::peekFront_runtime_error_on_empty() {
    Queue q;
    try {
        q.peekFront();
        return false;
    }
    catch(std::runtime_error& e) {
        return true;
    }
    return false;
}

void Test::print_test_status() {
    std::string passedMsg = passed ? "PASSED" : "FAILED";
    std::cout << "Test " << this->testCount
              << ": " << msg << ": " << passedMsg << '\n';
}

void Test::run_test(bool result, std::string msg) {
    passed = result;
    this->msg = msg;
    print_test_status();
    this->testCount++;
}

void Test::run() {
    run_test(empty_on_construction(), 
            "Newly constructed Queue is empty");

    run_test(is_empty(0),
            "isEmpty() returns true with 0 elements");

    run_test(dequeue_returns_value(),
            "dequeue() returns an integer value");

    for(int i=1; i < 102; i+=25) {
        run_test(!is_empty(i), 
                "isEmpty() does not return empty after " + std::to_string(i) + " enqueues");
    }

    for(int i=1; i < 102; i+=25) {
        run_test(enqueue_dequeue_same_size(i),
                "Enqueueing " + std::to_string(i) + " elements, then dequeueing " + std::to_string(i) + " elements results in empty queue");
    }

    for(int i=1; i < 102; i+=25) {
        run_test(enqueue_peekFront_same_content(i),
                "Enqueueing " + std::to_string(i) + " elements, then peeking " + std::to_string(i) + " elements results in same values");
    }

    for(int i=1; i < 102; i+=25) {
        run_test(enqueue_peekFront_same_content_stack(i),
                "Enqueueing " + std::to_string(i) + " elements, then peeking " + std::to_string(i) + " elements results in same values in reverse");
    }

    run_test(dequeue_runtime_error_on_empty(), 
            "Dequeue with empty queue throws a runtime error");

    run_test(peekFront_runtime_error_on_empty(),
            "Peeking front with empty queue results in runtime error");
}