#include <iostream>
#include <rate_limit/rate_limit.h>

rate_limit::rate_limit(std::function<void()> action_callback, int threshold,
                       int seconds) noexcept
    : action_(action_callback), threshold_(threshold), surpassed_(false),
      timer_(io_, boost::asio::chrono::seconds(seconds)) {}

bool rate_limit::increment_() {
    if ((this->count_++) > this->threshold_) {
        this->surpassed_ = true;
        return false;
    }
    return true;
}

void rate_limit::reset_() {
    this->surpassed_ = false;
}

bool rate_limit::send() {
    this->increment_();
    if (!this->surpassed_) {
        this->action_();
        return true;
    }
    return false;
}
