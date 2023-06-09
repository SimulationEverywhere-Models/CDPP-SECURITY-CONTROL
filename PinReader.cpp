/*******************************************************************
*
*  DESCRIPTION: Atomic Model PinReader (use a distribution)
*
*  AUTHOR: Yongsheng Yang
*
*  STUDENT#: 2736800
*  
*  EMAIL: yyang@site.uottawa.ca
*
*  DATE: 16/10/2001
*
*******************************************************************/

/** include files **/
#include <math.h>          // fabs( ... )
#include "PinReader.h"        // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: PinReader
* Description: constructor
********************************************************************/
PinReader::PinReader( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, out( addOutputPort( "out" ) )
{
	try
	{
		dist = Distribution::create( MainSimulator::Instance().getParameter( description(), "distribution" ) );

		MASSERT( dist );

		for ( register int i = 0 ; i < dist->varCount() ; i++ )
		{
			string parameter( MainSimulator::Instance().getParameter( description(), dist->getVar(i) ) ) ;
			dist->setVar( i, str2float( parameter ) ) ;
		}
	} catch( InvalidDistribution &e )
	{
		e.addText( "The model " + description() + " has distribution problems!" ) ;
		e.print(cerr);
		MTHROW( e ) ;
	} catch( MException &e )
	{
		MTHROW( e ) ;
	}
}

/*******************************************************************
* Function Name: externalFunction
* Description: the PinReader receives one job
********************************************************************/
Model &PinReader::externalFunction( const ExternalMessage &msg )
{
	pid = (int) msg.value();
	holdIn( active, Time( static_cast<float>( fabs( distribution().get() ) ) ) ) ;
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &PinReader::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &PinReader::outputFunction( const InternalMessage &msg )
{
	//cout<<" !! "<<pid<<endl;
	
	sendOutput( msg.time(), out,pid );
	return *this;
}

PinReader::~PinReader()
{
	delete dist;
}
