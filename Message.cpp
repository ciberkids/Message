/**
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2015 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 */


#include "Message.h"


//Constructor
MessageHelper::MessageHelper() { };

void MessageHelper::setSensorID(unsigned char id) {
  internalMessage_.sensor_id = id;
}
void MessageHelper::setSensorType(sensor_type type) {
  internalMessage_.sensorType = type;
}
void MessageHelper::setSensorInformationType(sensor_information_type type) {
  internalMessage_.informationType = type;
}
void MessageHelper::setCommand(sensor_command command) {
  internalMessage_.sensorCommand = command;
}
void MessageHelper::setSystemMessageType(system_message_type type) {
  internalMessage_.messageType = type;
}
void MessageHelper::setPayloadType(payload_type type) {
  internalMessage_.datatype = type;
}
void MessageHelper::setPayloadSize(unsigned char size) {
  internalMessage_.payloadsize = size;
}

unsigned char MessageHelper::getSensorID(){
  return internalMessage_.sensor_id;
}
sensor_type MessageHelper::getSensorType(){
  return internalMessage_.sensorType;
}
sensor_information_type MessageHelper::getSensorInformationType(){
  return internalMessage_.informationType;
}
sensor_command MessageHelper::getCommand() {
  return internalMessage_.sensorCommand;
}
system_message_type MessageHelper::getSystemMessageType() {
  return internalMessage_.messageType;
}
payload_type MessageHelper::getPayloadType() {
  return internalMessage_.datatype;
}
unsigned char  MessageHelper::getPayloadSize() {
  return internalMessage_.payloadsize;
}

char* MessageHelper::getPayload() {
  return internalMessage_.payload;
}

char* MessageHelper::toString() {
  char buf[100];
  /*
   * unsigned char sensor_id; // 1 byte
	sensor_command sensorCommand; // 1 byte
	sensor_type sensorType; // 1 byte
	system_message_type messageType; // 1 byte
	payload_type datatype; // 1 byte
	unsigned char payloadsize; // Max number 137
	char payload_[138];
   */
  sprintf_P(buf,
            PSTR("FromSensorID %u, command %u, sensorType %u, messageType %u, payloadtype %u, PayloadSize %u"),
            internalMessage_.sensor_id,
            internalMessage_.sensorCommand,
            internalMessage_.sensorType,
            internalMessage_.messageType,
            internalMessage_.datatype,
            internalMessage_.payloadsize);
  return buf;

}



//
//
//sensor_command MessageHelper::getCommand() const {
//	return internalMessage.sensorCommand;
//}
//
///* Getters for payload converted to desired form */
//void* MessageHelper::getCustom() const {
//	return (void *)data;
//}
//
//const char* MessageHelper::getString() const {
//	uint8_t payloadType = miGetPayloadType();
//	if (payloadType == P_STRING) {
//		return data;
//	} else {
//		return NULL;
//	}
//}
//
//// handles single character hex (0 - 15)
//char MessageHelper::i2h(uint8_t i) const {
//	uint8_t k = i & 0x0F;
//	if (k <= 9)
//		return '0' + k;
//	else
//		return 'A' + k - 10;
//}
//
//char* MessageHelper::getCustomString(char *buffer) const {
//	for (uint8_t i = 0; i < miGetLength(); i++)
//	{
//		buffer[i * 2] = i2h(data[i] >> 4);
//		buffer[(i * 2) + 1] = i2h(data[i]);
//	}
//	buffer[miGetLength() * 2] = '\0';
//	return buffer;
//}
//
//char* MessageHelper::getStream(char *buffer) const {
//	uint8_t cmd = miGetCommand();
//	if ((cmd == C_STREAM) && (buffer != NULL)) {
//		return getCustomString(buffer);
//	} else {
//		return NULL;
//	}
//}
//
//char* MessageHelper::getString(char *buffer) const {
//	uint8_t payloadType = miGetPayloadType();
//	if (buffer != NULL) {
//		if (payloadType == P_STRING) {
//			strncpy(buffer, data, miGetLength());
//			buffer[miGetLength()] = 0;
//		} else if (payloadType == P_BYTE) {
//			itoa(bValue, buffer, 10);
//		} else if (payloadType == P_INT16) {
//			itoa(iValue, buffer, 10);
//		} else if (payloadType == P_UINT16) {
//			utoa(uiValue, buffer, 10);
//		} else if (payloadType == P_LONG32) {
//			ltoa(lValue, buffer, 10);
//		} else if (payloadType == P_ULONG32) {
//			ultoa(ulValue, buffer, 10);
//		} else if (payloadType == P_FLOAT32) {
//			dtostrf(fValue,2,min(fPrecision, 8),buffer);
//		} else if (payloadType == P_CUSTOM) {
//			return getCustomString(buffer);
//		}
//		return buffer;
//	} else {
//		return NULL;
//	}
//}
//
//bool MessageHelper::getBool() const {
//	return getByte();
//}
//
//uint8_t MessageHelper::getByte() const {
//	if (miGetPayloadType() == P_BYTE) {
//		return data[0];
//	} else if (miGetPayloadType() == P_STRING) {
//		return atoi(data);
//	} else {
//		return 0;
//	}
//}
//
//
//float MessageHelper::getFloat() const {
//	if (miGetPayloadType() == P_FLOAT32) {
//		return fValue;
//	} else if (miGetPayloadType() == P_STRING) {
//		return atof(data);
//	} else {
//		return 0;
//	}
//}
//
//int32_t MessageHelper::getLong() const {
//	if (miGetPayloadType() == P_LONG32) {
//		return lValue;
//	} else if (miGetPayloadType() == P_STRING) {
//		return atol(data);
//	} else {
//		return 0;
//	}
//}
//
//uint32_t MessageHelper::getULong() const {
//	if (miGetPayloadType() == P_ULONG32) {
//		return ulValue;
//	} else if (miGetPayloadType() == P_STRING) {
//		return atol(data);
//	} else {
//		return 0;
//	}
//}
//
//int16_t MessageHelper::getInt() const {
//	if (miGetPayloadType() == P_INT16) {
//		return iValue;
//	} else if (miGetPayloadType() == P_STRING) {
//		return atoi(data);
//	} else {
//		return 0;
//	}
//}
//
//uint16_t MessageHelper::getUInt() const {
//	if (GetPayloadType() == P_UINT16) {
//		return uiValue;
//	} else if (miGetPayloadType() == P_STRING) {
//		return atoi(data);
//	} else {
//		return 0;
//	}
//
//}
//
//Message& MessageHelper::setType(uint8_t _type) {
//	type = _type;
//	return *this;
//}
//
//Message& MessageHelper::setSensor(uint8_t _sensor) {
//	sensor = _sensor;
//	return *this;
//}
//
//Message& MessageHelper::setDestination(uint8_t _destination) {
//	destination = _destination;
//	return *this;
//}
//
//// Set payload
//Message& MessageHelper::set(void* value, uint8_t length) {
//	miSetPayloadType(P_CUSTOM);
//	miSetLength(length);
//	memcpy(data, value, min(length, MAX_PAYLOAD_SIZE));
//	return *this;
//}
//
//Message& MessageHelper::set(const char* value) {
//	uint8_t length = value == NULL ? 0 : min(strlen(value), MAX_PAYLOAD_SIZE);
//	miSetLength(length);
//	miSetPayloadType(P_STRING);
//	if (length) {
//		strncpy(data, value, length);
//	}
//	// null terminate string
//	data[length] = 0;
//	return *this;
//}
//
//Message& MessageHelper::set(bool value) {
//	miSetLength(1);
//	miSetPayloadType(P_BYTE);
//	data[0] = value;
//	return *this;
//}
//
//Message& MessageHelper::set(uint8_t value) {
//	miSetLength(1);
//	miSetPayloadType(P_BYTE);
//	data[0] = value;
//	return *this;
//}
//
//Message& MessageHelper::set(float value, uint8_t decimals) {
//	miSetLength(5); // 32 bit float + persi
//	miSetPayloadType(P_FLOAT32);
//	fValue=value;
//	fPrecision = decimals;
//	return *this;
//}
//
//Message& MessageHelper::set(uint32_t value) {
//	miSetPayloadType(P_ULONG32);
//	miSetLength(4);
//	ulValue = value;
//	return *this;
//}
//
//Message& MessageHelper::set(int32_t value) {
//	miSetPayloadType(P_LONG32);
//	miSetLength(4);
//	lValue = value;
//	return *this;
//}
//
//Message& MessageHelper::set(uint16_t value) {
//	miSetPayloadType(P_UINT16);
//	miSetLength(2);
//	uiValue = value;
//	return *this;
//}
//
//Message& MessageHelper::set(int16_t value) {
//	miSetPayloadType(P_INT16);
//	miSetLength(2);
//	iValue = value;
//	return *this;
//}
//