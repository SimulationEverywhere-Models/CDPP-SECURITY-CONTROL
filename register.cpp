/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Rujun Hu
*
*  STUDENT#: 258902
*
*  EMAIL: rujun_hu@yahoo.ca
*
*  DATE: 16/10/2001
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "PinReader.h"
#include "queue.h"
#include "cpu1.h"
#include "cpu2.h"
#include "DoorLatch.h"

void MainSimulator::registerNewAtomics()
{
	
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<PinReader>() , "PinReader" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "Queue" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<DoorLatch>() , "DoorLatch" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CPU1>() , "CPU1" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CPU2>() , "CPU2" ) ;
	 } 

