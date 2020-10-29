//
// Created by luispedro on 24/10/20.
//

#include "MemoryUsage.h"
#include <sys/time.h>
#include <sys/resource.h>
#include <mach/mach.h>

/*!
 * Checks the amount of memory usage, resident set size and maximum resident set size (in MB)
 * @param vm_usage
 * @param resident_set
 * @param max_rss
 */
void MemoryUsage::MemUsage(double &vm_usage, double &resident_set, double &max_rss) {
    if (os->isLinux()) {
        ifstream stat_stream("/proc/self/stat", ios_base::in); //get info from proc directory
        //create some variables to get info
        string pid, comm, state, ppid, pgrp, session, tty_nr;
        string tpgid, flags, minflt, cminflt, majflt, cmajflt;
        string utime, stime, cutime, cstime, priority, nice;
        string O, itrealvalue, starttime;
        unsigned long vsize;
        long rss;
        stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
                    >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
                    >> utime >> stime >> cutime >> cstime >> priority >> nice
                    >> O >> itrealvalue >> starttime >> vsize >> rss; // don't care about the rest
        stat_stream.close();
        long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024.0; // for x86-64 is configured to use 2MB pages
        vm_usage = vsize / pow(1024.0, 2);//in MB
        resident_set = rss * page_size_kb / 1024.0;

        getrusage(RUSAGE_SELF, &usage);
        max_rss = usage.ru_maxrss / 1024.0;

        cout << "Virtual Memory: " << vm_usage << " MB" << "\nResident set size: " << resident_set << " MB"
             << "\nMax res set size " << max_rss << " MB" << endl;
    }
    else{

        struct rusage usage;
        if(0 == getrusage(RUSAGE_SELF, &usage)){
            max_rss = usage.ru_maxrss/1024;
        }

        struct mach_task_basic_info info;
        mach_msg_type_number_t infoCount = MACH_TASK_BASIC_INFO_COUNT;

        long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024;

        if ( task_info( mach_task_self( ), MACH_TASK_BASIC_INFO,
                        (task_info_t)&info, &infoCount ) != KERN_SUCCESS ){

            resident_set = (size_t)0L * page_size_kb/1024.0;
        }
        else{
            resident_set =  (size_t)info.resident_size * page_size_kb / pow(1024.0, 2);
        }

    }
}

MemoryUsage::MemoryUsage() {
    os = OS::GetInstance();
}

MemoryUsage::~MemoryUsage() {
    delete this;
}
