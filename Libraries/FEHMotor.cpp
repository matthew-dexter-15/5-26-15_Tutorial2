#include "FEHMotor.h"
#include "FEHProteus.h"

FEHMotor::FEHMotor( FEHMotorPort motorport )
{
    _motorport = motorport;
	_power = 0;
}

void FEHMotor::Stop()
{
	if( _power != 0 )
	{
		_power = 0;
		Propeller.SetMotorRate( (unsigned char)_motorport, (unsigned char)0, (unsigned char)30 );
	}
}

void FEHMotor::SetPower( int8 power )
{
	if( _power != power )
	{
		_power = power;
		Propeller.SetMotorRate( (unsigned char)_motorport, (unsigned char)power, (unsigned char)30 );
	}
}
