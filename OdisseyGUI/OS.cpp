//
// Created by luispedro on 24/10/20.
//

#include "OS.h"
OS* OS::os = nullptr;

OS *OS::GetInstance() {
    if (os == nullptr){
        bool is_linux = false;
        IsLinuxOS(is_linux);
        os = new OS(is_linux);
    }
    return os;
}

void OS::IsLinuxOS(bool &is_linux) {
#ifdef __linux__
    is_linux = true;
#endif

#ifdef __APPLE__
    is_linux = false;
#endif
}

/*!
 * is_linux getter
 * @return
 */
bool OS::isLinux() const {
    return is_linux;
}

OS::~OS() {
    delete os;
    delete this;
}

