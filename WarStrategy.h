#ifndef WARSTRATEGY_H
#define WARSTRATEGY_H

/**
 *  A WarStrategy class. Startegy Class which is abstract .
 */

class WarStrategy
{
    private:
        /* data */
    public:

        /**
       * A constructor.
       * Default War Startegy constructor.
       */
        WarStrategy();

       /**
       * A destructor.
       * War Strategy destructor.
       */
        ~WarStrategy();

        /**
       * A pure virtual member.
       * @see WarStrategy()
       * @see ~WarStrategy()
       */
        virtual void RulesofEngagement() = 0; 
};


#endif