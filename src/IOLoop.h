//
// Created by Neveralso on 15/3/15.
//

#ifndef _DEMONIAC_IOLOOP_H_
#define _DEMONIAC_IOLOOP_H_

#include <iostream>
#include <vector>
#include <map>

#include "Event.h"
#include "util/noncopyable.h"

#include "poller/GetPoller.h"

namespace dc {

class IOLoop : noncopyable {
private:
    const int MAX_EVENTS_READY_NUM = 100;

    //IOLoop *instance_;
    bool quit_;
    Poller *poller_;
    std::map<int, Event> events_;
    std::vector<poll_event> events_ready_;

public:
    IOLoop();

    static IOLoop *Current();

    void Loop();

    void AddEvent(const Event &e);

    void quit();

    ~IOLoop();
};

}


#endif //_DEMONIAC_IOLOOP_H_
