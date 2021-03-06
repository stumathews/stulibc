
/**
 * @file etcp.h
 * @brief Networking library routines.
 * @author Stuart Mathews
 * @date 22 March 2015
 *
 * This header contains the function and type declarations for dealing with low level networking functionality in the library.
 * This includes reading and writing to sockets and tcp and udp client and server routines
 * @see http://devel.stuartmathews.com/stulibc
 */

/** \page networking Networking
 This includes reading and writing to sockets and tcp and udp client and server routines
 \include etcp.h
 \include skel.h
 */


/** \example say.c
 * This is an example of how to use the netTcpClient
 * This starts off by using the cmd line parsing routines to get the desired port number to send data do.
 * Then it sends out the string Hello World to that port
 */

#ifndef __ETCP_H__
#define __ETCP_H__

/* Include standard headers */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <skel.h>
#include <constants.h>

#define NLISTEN			5		/* max waiting connections */
#define NSMB			5		/* number shared memory bufs */
#define SMBUFSZ			256		/* size of shared memory buf */

#ifdef __SVR4
#define bzero(b,n)	memset( ( b ), 0, ( n ) )
#endif 


typedef void ( *tofunc_t )( void * );

/** \brief Print a diagnostic and optionally quit
 *
 * \param status int status number
 * \param err int error number
 * \param fmt char* format of error string
 * \param ... aditional arguments that match the format string
 * \return void 
 *
 */
LIBRARY_API void netError( int status, int err, char* fmt, ... );

/** \brief Read and wait for len bytes on socket
 *
 * \param s SOCKET socket to read data from
 * \param buf char* address of memeory to store len bytes of data
 * \param len size_t the length of data to read/wait for 
 * \return int number of bytes read, or -1 on error 
 *
 */
LIBRARY_API int netReadn( SOCKET s, char* buf, size_t len );

/** \brief Read variable records (expects first data read to be size of remaining data)
 *
 * \param s SOCKET socket to read data from
 * \param buf char* address of memeory to store len bytes of data
 * \param len size_t the length of data to read/wait for 
 * \return int number of bytes read, or -1 on error 
 *
 */
LIBRARY_API int netReadVRec( SOCKET s, char* buf, size_t len );
LIBRARY_API int netReadcrlf( SOCKET, char *, size_t );
LIBRARY_API int netReadLine( SOCKET, char *, size_t );

/** \brief Set up for tcp server: get tcp socket, bound to hname:sname and returns socket.
 *
 * \param hname char* hostname that we'll bind the socket to
 * \param sname char* the port number for the socket
 * \return socket configuured to listen on hname host and sname port 
 *
 */
LIBRARY_API SOCKET netTcpServer( char* hname, char* sname );

/** \brief Set up for tcp client socket, then connect to it and return socket
 *
 * \param hname char* hostname that we'll bind the socket to
 * \param sname char* the port number for the socket
 * \return socket that represents the established connection  
 *
 */
LIBRARY_API SOCKET netTcpClient( char* hname, char* sname );

/** \brief Set up for udp server: get udp socket bound to hname:sname
 *
 * \param hname char* hostname that we'll bind the socket to
 * \param sname char* the port number for the socket
 * \return socket that represents hname host and sname port 
 *
 */
LIBRARY_API SOCKET netUdpServer( char* hname, char* sname );

/** \brief Set up for udp client: get a udp socket and fill address to use(this never blocks)
 *
 * \param hname char* hostname that we'll bind the socket to
 * \param sname char* the port number for the socket
 * \param addr struct sockaddr_in* address to use
 * \return a raw simple udp socket  
 *
 */
LIBRARY_API SOCKET netUdpClient( char* hname, char* sname, struct sockaddr_in* sap );

int tselect( int, fd_set *, fd_set *, fd_set *);
unsigned int timeout( tofunc_t, void *, int );
void untimeout( unsigned int );
void init_smb( int );
void *smballoc( void );
void smbfree( void * );
void smbsend( SOCKET, void * );
void *smbrecv( SOCKET );

/** \brief fill in a sockaddr_in structure
 *
 * \param hname char* hostname string
 * \param sname char* port number as string
 * \param sap struct sockaddr_in* address structure to fill
 * \param protocol char* the protocol to set in the address structure
 * \return void the pointer sap will be filled up and available to caller
 *
 */
LIBRARY_API void netSetAddress( char* hname, char* sname, struct sockaddr_in* sap, char* protocol );

#endif  /* __ETCP_H__ */
