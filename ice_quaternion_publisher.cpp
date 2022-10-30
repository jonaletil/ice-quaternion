// include topic data
#include "topic_data.hpp"

// include publisher, signal handler and runtime
#include "iceoryx_posh/popo/publisher.hpp"
#include "iceoryx_dust/posix_wrapper/signal_watcher.hpp"
#include "iceoryx_posh/runtime/posh_runtime.hpp"

#include <iostream>
#include <cstdlib>

constexpr char APP_NAME[] = "ice-quaternion-publisher";

void getQuaternionObject(QuaternionObject* const object, const float& val) noexcept
{
*object = QuaternionObject(val, val, val, val);
}

int main()
{
    // initialize runtime for communication with RouDi
    iox::runtime::PoshRuntime::initRuntime(APP_NAME);

    // create a publisher object
    iox::popo::Publisher<QuaternionObject> publisher({"Quaternion", "QuaternionMessage", "Object"});

    float counter = 0.0;
    while (!iox::posix::hasTerminationRequested())
    {
        ++counter;
        // generate random number
        float random = static_cast <float> (rand()) / static_cast <float> (RAND_MAX/100);


        float sampleValue1 = random;
        float sampleValue2 = random / 6;
        float sampleValue3 = random / 7;
        float sampleValue4 = random / 8;

        // Reserve a memory chunk which fits our struct.
        // Retrieve a typed sample from shared memory.
        publisher.loan()
                .and_then([&](auto& sample) {
                    sample->w = sampleValue1;
                    sample->x = sampleValue2;
                    sample->y = sampleValue3;
                    sample->z = sampleValue4;
                    sample.publish();
                })
                .or_else([](auto& error) {
                    // Do something with error
                    std::cerr << "Unable to loan sample, error: " << error << std::endl;
                });

        // print to console
        std::cout << "Counter: " << counter << std::endl << "Publisher sent values: " << sampleValue1 << ", " << sampleValue2 << ", " << sampleValue3
                  << ", " << sampleValue4 << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    return 0;
}

