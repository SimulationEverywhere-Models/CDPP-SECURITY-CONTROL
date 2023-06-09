/*******************************************************************
*
*  DESCRIPTION: class CPU2 (processes jobs with a specified
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


#ifndef __CPU2_H
#define __CPU2_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
class Distribution ;

/** declarations **/
class CPU2: public Atomic
{
public:
	CPU2( const string &name = "CPU2" ) ;	 // Default constructor

	~CPU2();					// Destructor

	virtual string className() const
		{return "CPU2";}

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
};	// class CPU2


#endif   //__CPU2_H 
