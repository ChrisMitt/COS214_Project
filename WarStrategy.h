#ifndef WARSTRATEGY_H
#define WARSTRATEGY_H

class WarStrategy
{
    private:
        /* data */
    public:
        WarStrategy();
        ~WarStrategy();
        virtual void RulesofEngagement() = 0; 
};


#endif