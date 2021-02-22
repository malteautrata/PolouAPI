//============================================================================
// Name        : main.cpp
// Author      : Willi Penner
//
// Description : Contains the main function. It also contains test functions
//               to test the connection to the controller and the movement of
//       		 the servos.
//============================================================================

#include "SerialCom.hpp"
#include "Pololu.hpp"
#include "ServoMotor.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	try{
        int degree1;
        int degree2;
        int degree3;

        cout << "Bitte Zielposition von Motor 1 in Grad angeben: ";
        cin >> degree1;
        
        cout << "Bitte Zielposition von Motor 2 in Grad angeben: ";
        cin >> degree2;
        
        cout << "Bitte Zielposition von Motor 3 in Grad angeben: ";
        cin >> degree3;
        
		const char* portName = "/dev/cu.usbmodem003079441";  // Mac
		Pololu conn(portName, 9600);
		// Open connection to COM port.
		conn.openConnection();
		conn.getErrors();
		//return 0;

        
        
		// Define the servos of the robot manipulator
		ServoMotor arm_0(0, 6000, 3000	, &conn);
        ServoMotor arm_1(1, 6000, 3000  , &conn);
        ServoMotor arm_2(2, 6000, 3000  , &conn);
        
        cout << "Arm 1: " << arm_0.getMaxPosInAbs() << endl;
		cout << "max. pos.: " << arm_0.getMaxPosInAbs() << endl;
		cout << "min. pos.: " << arm_0.getMinPosInAbs() << endl;
		cout << "get current pos.: "  << arm_0.getPositionInAbs() << endl;
        
        
        cout << "Arm 2: " << arm_1.getMaxPosInAbs() << endl;
        cout << "max. pos.: " << arm_1.getMaxPosInAbs() << endl;
        cout << "min. pos.: " << arm_1.getMinPosInAbs() << endl;
        cout << "get current pos.: "  << arm_1.getPositionInAbs() << endl;
        
        cout << "Arm 3: " << arm_2.getMaxPosInAbs() << endl;
        cout << "max. pos.: " << arm_2.getMaxPosInAbs() << endl;
        cout << "min. pos.: " << arm_2.getMinPosInAbs() << endl;
        cout << "get current pos.: "  << arm_2.getPositionInAbs() << endl;
        
		unsigned short pMin, pMid, pMax;
		arm_0.showPololuValues(pMin,pMid,pMax);
		cout << pMin	<< " " << pMid << " " << pMax << endl;

		arm_0.setMinMaxDegree(-45,45);
		arm_0.setPositionInDeg(degree1);
        //arm_0.setPositionInAbs(3000);
        arm_0.setSpeed(80);
        arm_0.setAcceleration(80);
        
        arm_1.setMinMaxDegree(-45,45);
        arm_1.setPositionInDeg(degree2);
        arm_1.setSpeed(80);
        arm_1.setAcceleration(80);

        arm_2.setMinMaxDegree(-45,45);
        arm_2.setPositionInDeg(degree3);
        arm_2.setSpeed(80);
        arm_2.setAcceleration(80);

		conn.closeConnection();
	}catch(IException *e){
		cout << e->getMsg() << endl;
	}catch(string e){
		cout << "string Error: " << e << endl;
	}catch(...){
		cout << "unknown error\n";
	}

	return 0;
}
