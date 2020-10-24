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
#ifdef linux
    is_linux = true;
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

