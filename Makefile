# Makefile for Sun RPC Extended Calculator

CC = gcc
CFLAGS += -g -I/usr/include/tirpc
LDLIBS += -ltirpc -lm
RPCGEN = rpcgen

CLIENT = calculator_client
SERVER = calculator_server

SOURCES_CLNT.c = calculator_clnt.c calculator_client.c calculator_xdr.c
SOURCES_SVC.c = calculator_svc.c calculator_server.c calculator_xdr.c
SOURCES.x = calculator.x

TARGETS = calculator.h calculator_xdr.c calculator_clnt.c calculator_svc.c

all: $(CLIENT) $(SERVER)

$(TARGETS): $(SOURCES.x)
	$(RPCGEN) $(SOURCES.x)

$(CLIENT): $(SOURCES_CLNT.c) $(TARGETS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(SOURCES_CLNT.c) $(LDLIBS)

$(SERVER): $(SOURCES_SVC.c) $(TARGETS)
	$(CC) $(CFLAGS) -o $(SERVER) $(SOURCES_SVC.c) $(LDLIBS)

clean:
	$(RM) $(CLIENT) $(SERVER) *.o
