#include "object.h"
#include <iostream>

test::test() : i(0), l(rate_limit(std::bind(&test::callback, this), 5, 5)) {}

void test::callback() {
    std::cout << i << '\n';
    i++;
    std::cout << i << '\n';
}

void test::do_stuff() {
    for (int i = 0; i < 10; i++) {
        if (!this->l.send()) {
            std::cout << "limit exceeded\n";
        }
    }
}
