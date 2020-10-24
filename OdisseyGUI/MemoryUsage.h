//
// Created by luispedro on 24/10/20.
//
#pragma once
#include <unistd.h>
#include <ios>
#include <iostream>
#include <fstream>
#include <string>
#include <sys/resource.h>
#include <math.h>

using namespace std;

class MemoryUsage {
private:
    struct rusage usage;

public:
    MemoryUsage();
    ~MemoryUsage();
    void MemUsage(double &vm_usage, double &resident_set, double &max_rss);
};


