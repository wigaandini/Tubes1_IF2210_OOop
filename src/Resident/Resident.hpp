#ifndef __RESIDENT_HPP_
#define __RESIDENT_HPP_


class Resident {
    public:
        virtual int tax() = 0;
        virtual void harvest() = 0;
};
#endif