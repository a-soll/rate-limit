#ifndef RATE_LIMIT_H
#define RATE_LIMIT_H

#include <boost/asio.hpp>
#include <functional>

class rate_limit {
  public:
    rate_limit(std::function<void()> action_callback, int threshold,
               int seconds) noexcept;
    bool send();

  private:
    std::function<void()> action_;
    int threshold_; // threshold in seconds
    int count_;
    bool surpassed_;
    boost::asio::steady_timer timer_;
    boost::asio::io_context io_;
    bool increment_();
    void reset_();
};

#endif /* RATE_LIMIT_H */
