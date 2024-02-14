#include "object.h"
#include <iostream>

test::test() : i(0), l(rate_limit(std::bind(&test::callback, this), 5)) {}

void test::callback() {
    i++;
    std::cout << i << '\n';
}

void test::do_stuff() {
    this->l.send();
}
