/** @file traceback.c
 *  @brief The traceback function
 *
 *  This file contains the traceback function for the traceback library
 *
 *  @author Harry Q. Bovik (hqbovik)
 *  @bug Unimplemented
 */
//#include "traceback_utils.h"
#include "traceback_internal.h"

void *get_frame_pointer();
void traceback(FILE *fp)
{
	/* the following just makes a sample access to "functions" array. 
	 * note if "functions" is not referenced somewhere outside the 
	 * file that it's declared in, symtabgen won't be able to find
	 * the symbol. So be sure to always do something with functions */

	/* remove this line once you've got real code here */
	/*int i;
	for(i=0;i<sizeof(functions)/sizeof(functsym_t);i++) {
		printf("first function in table name: %s ", functions[i].name);
		printf("address %p\n", functions[i].addr);
	}*/
	void *ebp;
	printf("first function in table name: %s ", functions[0].name);

	/*get the ebp*/
	ebp=get_frame_pointer();
	//printf("Frame address is %p\n",ebp);

	
}


