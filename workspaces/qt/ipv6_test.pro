#   
# file:			ipv6_test.pro  
# created on:	2020 Aug 16 
# created by:	D. Kalantaryan (davit.kalantaryan@gmail.com)  
#  


TEMPLATE = subdirs

SUBDIRS		+=	$${PWD}/../../prj/tests/ipv6_tcp_server_test_qt/ipv6_tcp_server_test.pro
SUBDIRS		+=	$${PWD}/../../prj/tests/ipv6_tcp_client_test_qt/ipv6_tcp_client_test.pro

OTHER_FILES	+=	\
	$${PWD}/../../README.md						\
	$${PWD}/../../.gitignore
