//
// Created by a on 7/5/20.
//

#include "Status.h"

const char *Status::get() {
    return m_status;
}

const char* const Status::statuses[] = {"new","modified","up to date"};

void Status::set(EStatus status)
{
    m_status = statuses[status];
}
