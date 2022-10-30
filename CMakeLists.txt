# Build icequaternion example
cmake_minimum_required(VERSION 3.16)
project(ice-quaternion)

include(GNUInstallDirs)

find_package(iceoryx_platform REQUIRED)
find_package(iceoryx_posh CONFIG REQUIRED)
find_package(iceoryx_hoofs CONFIG REQUIRED)

include(IceoryxPackageHelper)
include(IceoryxPlatform)
include(IceoryxPlatformSettings)

iox_add_executable(
    TARGET  ice-quaternion-publisher
    FILES ice_quaternion_publisher.cpp
    LIBS    iceoryx_posh::iceoryx_posh
)

iox_add_executable(
    TARGET  ice-quaternion-subscriber
    FILES ice_quaternion_subscriber.cpp
    LIBS    iceoryx_posh::iceoryx_posh
)
