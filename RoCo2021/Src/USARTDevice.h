/*
 * USARTDevice.h
 *
 *  Created on: Jul 14, 2021
 *      Author: arion
 */

#ifndef LIBRARIES_ROCO_SRC_USARTDEVICE_H_
#define LIBRARIES_ROCO_SRC_USARTDEVICE_H_

#include <initializer_list>
#include <cstdint>


enum USARTDeviceType {
	MASTER, SLAVE
};

class USARTDevice {
public:
	USARTDeviceType getType();

protected:
	USARTDevice(USARTDeviceType type);
	virtual ~USARTDevice();

private:
	USARTDeviceType type;
};

class USARTMaster : public USARTDevice {
public:
	USARTMaster(std::initializer_list<uint8_t> slaves);
	uint8_t* getSlaves();
	uint8_t getNumSlaves();

private:
	uint8_t slaves[256];
	uint8_t num_slaves;
};

class USARTSlave : public USARTDevice {
public:
	USARTSlave();
};


#endif /* LIBRARIES_ROCO_SRC_USARTDEVICE_H_ */
