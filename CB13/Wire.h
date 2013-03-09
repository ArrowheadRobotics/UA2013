/*
 * Defines wires
 */
#ifndef WIRE_H
#define WIRE_H

//PWM
#define portLEFTDRIVE 1
#define portRIGHTDRIVE 2
#define portELEVATION 3
#define portSHOOTER 4
#define portWINCH 5
#define portDUMP 6
#define portPLACEHOLDER 7
#define portRLIGHTS 8
#define portGLIGHTS 9
#define portBLIGHTS 1O

//RELAY
#define portCONVEYOR 1
#define portCOMPRESSOR 2

//MODULES
#define moduleONE 1
#define moduleTWO 2

//SOLENOID OBJECTS
#define portCHUTELOWEXTEND 1
#define portCHUTELOWRETRACT 2
#define portCHUTEHIGHEXTEND 3
#define portCHUTEHIGHRETRACT 4
#define portFIRINGPININ 5
#define portFIRINGPINOUT 6
#define portGATEEXTEND 1
#define portGATERETRACT 2
#define portFORKUP 3
#define portFORKDOWN 4
#define portARMSUP 5
#define portARMSDOWN 6

//IO
//NO - Normally open
//NC - Normally closed
//SW - Switch
//Encoders use two ports: A and B
#define ioOPTICALSPEEDSENSOR 1
#define ioELEVATIONENCODERA 2
#define ioELEVATIONENCODERB 3
#define ioDRIVEENCODERRIGHTA 4
#define ioDRIVEENCODERRIGHTB 5 
#define ioDRIVEENCODERLEFTA 6 
#define ioDRIVEENCODERLEFTB 7
#define ioFORKLIFTSWNO 8
#define ioELEVATIONSWNC 9
#define ioCOMPPRESSURESW 10

#endif

