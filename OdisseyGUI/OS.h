//
// Created by luispedro on 24/10/20.
//

#pragma once

/*!
 * Class that indicates the OS used (Linux or Mac). Implements a Singleton Pattern Design
 */
class OS {
protected:
    OS(bool is_linux) : is_linux(is_linux){

    }
    static OS* os;
    bool is_linux;

public:
    ~OS();

    /*!
     * Makes the singleton object non-cloneable
     */
    OS(OS &other) = delete;

    /*!
     * Makes singleton object non-assignable
     */
    void operator = (const OS &) = delete;

    /*!
     * Static methos that controls access to the singleton instance
     */
     static OS * GetInstance();

     /*!
      * Method that checks whether the OS used is Linux or Mac
      */
     static void IsLinuxOS(bool &is_linux);


    bool isLinux() const;
};


