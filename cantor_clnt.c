/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "cantor.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

results *
cantorforeward_1(pairs *argp, CLIENT *clnt)
{
	static results clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, CantorForeward,
		(xdrproc_t) xdr_pairs, (caddr_t) argp,
		(xdrproc_t) xdr_results, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

pairs *
cantorbackward_1(results *argp, CLIENT *clnt)
{
	static pairs clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, CantorBackward,
		(xdrproc_t) xdr_results, (caddr_t) argp,
		(xdrproc_t) xdr_pairs, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
