/* this file allows a simple method of tracing. In this way the developers can
 * find the errors quickly and fix them better.
 */

#ifndef DEBUG_H
#define DEBUG_H

/** this macro is defined to make an output on the terminal to allow the
  * developers to check the value of the variables.*/
#define DEB(a) std::cout<<(a)<<"\n";
#define DBG(a) {a;} /**< this macro allows to do something in "debug mode".*/

#endif
