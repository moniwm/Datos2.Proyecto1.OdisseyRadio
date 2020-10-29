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
#include "OS.h"


using namespace std;

/*!
 * Class that implements method that check for memory usage
 */
class MemoryUsage {
private:
    struct rusage usage;

public:
    MemoryUsage();
    ~MemoryUsage();
    void MemUsage(double &vm_usage, double &resident_set, double &max_rss);
    OS *os;
};