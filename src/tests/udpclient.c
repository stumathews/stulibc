#include <etcp.h>

char *program_name;


/* client - place holder for server */
static void client( SOCKET s, struct sockaddr_in *peerp )
{
    int rc;
    int peerlen;
    char buf[120];

    peerlen = sizeof(*peerp);

    // You can send and receive directly on a raw udp socket
    // to send to and get from the address mentioned by *peerp

    if( sendto( s, "",1,0, (struct sockaddr*) peerp, peerlen) < 0 )
        netError( 1, errno, "sendto failed" );

    rc = recvfrom( s, buf, sizeof(buf), 0, (struct sockaddr*) peerp, &peerlen );
    if( rc >= 0 )
        write(1, buf, rc);
    else
        netError( 1, errno, "recvfrom failed");

}

/* main - UDP client setup */
int main( int argc, char **argv )
{
	struct sockaddr_in peer;
	SOCKET s;

	NETINIT();

    // get a raw udp socket for this address (NB: rmeember this is alwaysi ever non-blocking)
    s = netUdpClient( "localhost", "9000", &peer);

    // send/get data from upd socket (blocking functions)
	client( s, &peer );
	exit( 0 );
}
