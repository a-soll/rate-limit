#include <rate_limit/rate_limit.h>

class test {
  public:
    int i;
    test();
    void do_stuff();

  private:
    rate_limit l;
    void callback();
};
