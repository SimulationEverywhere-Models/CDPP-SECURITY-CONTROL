/*******************************************************************
*
*  DESCRIPTION: class PinReader
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



#ifndef __PINREADER_H
#define __PINREADER_H
#include "atomic.h"  

class Distribution ;

class PinReader: public Atomic
{
public:
	PinReader( const string &name = "PinReader" ) ;	

	~PinReader();					

	virtual string className() const
		{return "PinReader";}

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
};	// class PinReader


#endif   //__PINREADER_H 
