#pragma once

#include <iostream>
#include <chrono>
#include <vector>
#include <string>

struct Timing
{
    std::string Tag;
    double Duration;
};

class TimerReport {
    std::vector<Timing> Timings;
    std::string ReportName = "Timer Report";

public:
    void Add(Timing NewTiming);

    int Length();

    void Rename(const std::string& NewName);

    ~TimerReport();
};

class Timer {
    std::string Tag;
    std::chrono::time_point <std::chrono::high_resolution_clock> StartingTime;

public:
    Timer(const std::string& Name);

    void Rename(const std::string& NewName);

    void Start();

    void End(TimerReport* Report);
};