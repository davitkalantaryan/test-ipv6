#   
# file:			ipv6_test.pro  
# created on:	2020 Aug 16 
# created by:	D. Kalantaryan (davit.kalantaryan@gmail.com)  
#  

include ($${PWD}/../../common/common_qt/sys_common.pri )

QT -= gui
QT -= core
QT -= widgets
CONFIG -= qt


SOURCES	+=	\
	$${PWD}/../../../src/tests/main_ipv6_tcp_client_test.cpp


HEADERS	+=	\
	$${PWD}/../../../src/tests/ipv6_tcp_server_client_common.h
