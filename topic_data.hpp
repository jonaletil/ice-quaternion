#ifndef IOX_EXAMPLES_ICEDELIVERY_TOPIC_DATA_HPP
#define IOX_EXAMPLES_ICEDELIVERY_TOPIC_DATA_HPP

// topic data
struct QuaternionObject
{
    QuaternionObject() noexcept
    {
    }
    QuaternionObject(float w, float x, float y, float z) noexcept
        : w(w)
        , x(x)
        , y(y)
        , z(z)
    {
    }
    float w = 0.0;
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
};

#endif
