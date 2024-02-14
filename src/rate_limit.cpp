#include <rate_limit/rate_limit.h>

rate_limit::rate_limit(std::function<void()> action_callback, int threshold) noexcept
    : action_(action_callback), threshold_(threshold), surpassed_(false) {}

bool rate_limit::send() {
    if (!this->surpassed_) {
        this->action_;
        return true;
    }
    return false;
}
