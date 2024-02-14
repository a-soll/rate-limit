#ifndef RATE_LIMIT_H
#define RATE_LIMIT_H

#include <functional>
#include <boost/asio.hpp>

class rate_limit {
    std::function<void()> action_;
    int threshold_; // threshold in seconds
    bool surpassed_;

  public:
    rate_limit(std::function<void()>, int threshold) noexcept;
    bool send();
};

#endif /* RATE_LIMIT_H */
