#pragma once

template <typename T>
void clamp(T* value, T min, T max) {
    if (*value < min) {
        *value = min;
    } else if (*value > max) {
        *value = max;
    }
}