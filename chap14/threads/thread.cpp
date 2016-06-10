#include <QtCore>
#include <iostream>

#include "thread.h"

Thread::Thread():stopped(false){} //构造函数

void Thread::setMessage(const QString &message)
{
    messageStr = message;
}

void Thread::run()
{
    while (!stopped)
        std::cerr << qPrintable(messageStr);
    stopped = false;
    std::cerr << std::endl;
}

void Thread::stop()
{
    stopped = true;
}
