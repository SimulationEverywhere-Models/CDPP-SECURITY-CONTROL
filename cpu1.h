/*******************************************************************
*
*  DESCRIPTION: class CPU (processes jobs with a specified
*               distribution)
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/


#ifndef __CPU1_H
#define __CPU1_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
class Distribution ;

/** declarations **/
class CPU1: public Atomic
{
public:
	CPU1( const string &name = "CPU1" ) ;	 // Default constructor

	~CPU1();					// Destructor

	virtual string className() const
		{return "CPU1";}

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
};	// class CPU


#endif   //__CPU1_H 
