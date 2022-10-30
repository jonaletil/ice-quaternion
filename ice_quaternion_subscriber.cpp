// include topic data
#include "topic_data.hpp"

// include subscriber, signal handler and runtime
#include "iceoryx_posh/popo/subscriber.hpp"
#include "iceoryx_dust/posix_wrapper/signal_watcher.hpp"
#include "iceoryx_posh/runtime/posh_runtime.hpp"

#include <iostream>

constexpr char APP_NAME[] = "ice-quaternion-subscriber";

int main() {
    // initialize runtime
    iox::runtime::PoshRuntime::initRuntime(APP_NAME);

    // create a subscriber object
    iox::popo::Subscriber <QuaternionObject> subscriber({"Quaternion", "QuaternionMessage", "Object"});

    int counter = 0;
    // run until interrupted by Ctrl-C
    while (!iox::posix::hasTerminationRequested())
    {
        ++counter;
        subscriber
                .take()
                .and_then([counter](auto &sample) {
                    // print to console
                    std::cout << "Counter: " << counter << std::endl << "Subscriber got values: " << sample->w << ", "
                              << sample->x << ", " << sample->y
                              << ", " << sample->z << std::endl;
                })
                .or_else([](auto &result) {
                    // only has to be called if the alternative is of interest,
                    // i.e. if nothing has to happen when no data is received and
                    // a possible error alternative is not checked or_else is not needed
                    if (result != iox::popo::ChunkReceiveResult::NO_CHUNK_AVAILABLE) {
                        std::cout << "Error receiving chunk." << std::endl;
                    }
                });

        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    return (EXIT_SUCCESS);
}
