project(jackshome)

set(CMAKE_CXX_STANDARD 20)

set (SOURCES
    src/main.cpp
    src/schedulable.cpp
    src/scheduler.cpp
    src/event.cpp
    src/oneshot_schedulable.cpp
    src/cyclic_schedulable.cpp
    src/sync_plugin.cpp
    src/scheduled_block.cpp
    src/block.cpp
    src/data.cpp
    src/pulse_generator.cpp
    src/data_provider_meta.cpp
    src/named_data_provider.cpp
    src/connectable.cpp
    src/data_store.cpp
    src/source.cpp
    src/feedable.cpp
    src/final_sink.cpp
    src/delay.cpp
    src/event_callable.cpp
)

find_library(LIB_PTHREAD pthread)

add_executable(scheduler ${SOURCES})
target_link_libraries(scheduler PRIVATE ${LIB_PTHREAD})
target_include_directories(scheduler PRIVATE
    include
    3rd_party/asio-1.20.0/include
    plugins
    ${PROJECT_SOURCE_DIR}
)