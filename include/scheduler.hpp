#pragma once
#include <chrono>
#include <memory>
#include <vector>

namespace jhm
{
    class schedulable;
    class scheduler
    {
     public:
        using clock = std::chrono::high_resolution_clock;
        scheduler();

        // void add(schedulable&& s);
        schedulable& add(std::unique_ptr<schedulable>&& s);
        ~scheduler();

        static scheduler* get();

        void run(bool& stop_requested, clock::duration minimum_scheduling_duration,
                 clock::duration maximum_scheduling_duration);

     private:
        std::vector<std::unique_ptr<schedulable>> _schedulables;
    };
}  // namespace jhm.