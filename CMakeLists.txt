

generate_arduino_library(MessageLib
        BOARD ${BOARD}
        HDRS Message.h
        SRCS Message.cpp
        LIBS RF24NetworkLib
        )
