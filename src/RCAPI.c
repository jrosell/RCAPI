#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>


// Add 1 to the first element of a double vector
SEXP RCAPI_add_one(SEXP a) {

  // Alloc double(1) on "SEPX out" with garbage collector protection
  SEXP out = PROTECT(Rf_allocVector(REALSXP, 1));
  
  // Rf_asReal returns a double(1) corresponding to the first element of the SEXP object
  // With REAL we access double* of the SEXP object. C is 0-index based
  REAL(out)[0] = Rf_asReal(a) + 1; 

  // Unprotect 1 of the 1 protected objects
  UNPROTECT(1);

  // Return is required in C, optional in R
  return out;
}

