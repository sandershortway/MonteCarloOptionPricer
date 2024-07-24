#include "Timer.h"

void TimerReport::Add(Timing NewTiming)
{
    Timings.push_back(NewTiming);
}

size_t TimerReport::Length()
{
    return Timings.size();
}

void TimerReport::Rename(const std::string& NewName)
{
    ReportName = NewName;
}

TimerReport::~TimerReport()
{
    std::cout << ReportName << ":" << std::endl;

    for (const auto Timing : Timings) {
        std::cout << " - " << Timing.Tag << ": " << Timing.Duration << " ms" << std::endl;
    }
}

Timer::Timer(const std::string& Name) : Tag(Name)
{
    Start();
}

void Timer::Rename(const std::string& NewName)
{
    Tag = NewName;
}

void Timer::Start()
{
    StartingTime = std::chrono::high_resolution_clock::now();
}

void Timer::End(TimerReport* Report)
{
    std::chrono::time_point <std::chrono::high_resolution_clock> EndingTime = std::chrono::high_resolution_clock::now();
    double Duration = std::chrono::duration_cast<std::chrono::milliseconds>(EndingTime - StartingTime).count();
    Report->Add(Timing{ Tag, Duration });
}