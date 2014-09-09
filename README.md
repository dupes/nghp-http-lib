This library implements the get/set http protocol for communicating with the
"Cool Data" Controller.  The main class the programmer will interact with is
  NGHP
  
For API information, see the header file NGHP.h

The program relies on libcurl for all http and socket communication.
  http://curl.haxx.se/libcurl/

The following command will build the test program:
  g++ *.cpp -lcurl -o nghp

This command will build a test program called nghp.

Running the program with no parameters will print the help for the program.

All calls to functions on the NGHP object, including instantiation, should 
be wrapped with a try/catch block as demonstrated in main.cpp.  If you don't
want to deal with C++ exception handling, the NGHP class can be modified to
catch all curl errors.  This would requiring changing all of the function
signatures and adding a function to retrieve error information.
