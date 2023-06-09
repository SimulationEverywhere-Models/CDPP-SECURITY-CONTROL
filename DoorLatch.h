/*******************************************************************
*
*  DESCRIPTION: class DoorLatch
*
*  AUTHOR: Yongsheng Yang
*
*  STUDENT#: 2736800
*
*  EMAIL: yyang@site.uottawa.ca  
*
*  DATE: 15/10/2002
*
*******************************************************************/



#ifndef __DOORLATCH_H
#define __DOORLATCH_H
#include "atomic.h"  

class Distribution ;

class DoorLatch: public Atomic
{
public:
	DoorLatch( const string &name = "DoorLatch" ) ;	

	~DoorLatch();					

	virtual string className() const
		{return "DoorLatch";}

protected:
	Model &initFunction()
		{return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
        const Port &in ;
	Port &out ;
	Distribution *dist ;
	int pid ;
	

	Distribution &distribution()
			{return *dist;}
};	// class DoorLatch


#endif   //__DOORLATCH_H 
