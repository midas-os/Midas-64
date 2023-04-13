#ifndef H_MIDAS_MATH
#define H_MIDAS_MATH

float clamp(float value, float min, float max) {
    if (value < min) {
        value = min;
    } else if (value > max) {
        value = max;
    }

    return value;
}

#endif