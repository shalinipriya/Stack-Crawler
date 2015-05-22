/** @file traceback.c
 *  @brief The traceback function
 *
 *  This file contains the traceback function for the traceback library
 *
 *  @author Harry Q. Bovik (hqbovik)
 *  @bug Unimplemented
 */
#include "traceback_utils.h"
#include "traceback_internal.h"

int get_function(int return_address) {
//int get_function(void *addr) {
/*	int i;
	printf("%p\n",(int*)addr);	
	for(i=0;i<FUNCTS_MAX_NUM;i++) {
	//	printf("function  -%p %s, incoming address -%p\n", (int*)functions[i].addr, functions[i].name, (int*)addr);
		if((int*)addr == (int*)functions[i].addr)
			return i;
	}
	return -1;
*/
	printf("%x\n",return_address);
    int index = -1;

    /* go through the function list and find the function list index */
    while (++index < FUNCTS_MAX_NUM && strlen(functions[index].name) != 0) {
        if ((int)functions[index].addr > return_address) {
            break;
        }
    }

    /* check the return function is right */
    if (index >= 0 && return_address - (int)functions[index].addr
        < MAX_FUNCTION_SIZE_BYTES) {
        return index-1;
    }
    return -1;

}


void traceback(FILE *fp)
{
	/* the following just makes a sample access to "functions" array. 
	 * note if "functions" is not referenced somewhere outside the 
	 * file that it's declared in, symtabgen won't be able to find
	 * the symbol. So be sure to always do something with functions */

	/* remove this line once you've got real code here */
	int i, count=0,index;
	void *ebp, *old_ebp,*esp;
	int *return_address, *function_address;
	printf("first function in table name: %s\n", functions[0].name);
	int a =0,b;
	b=a;
	for(i=0;i<FUNCTS_MAX_NUM;i++) {
		printf("%s %p\n", functions[i].name, (int*)functions[i].addr);
	}
	/*get the ebp*/
	ebp=get_frame_pointer();
	esp=get_stack_pointer();
	
	while (1) {
		old_ebp=*(int*)(ebp);
		printf("ebp %p\n",(int*)(ebp));
		printf("esp %p\n",(int*)(esp));
		printf("ebp value %p\n",*(int*)(ebp));
		printf("addres on stack where return address is stored %p\n",(char*)(ebp)+4);
		return_address = *(int*)((char*)ebp+4);
		printf("Return address %p\n",return_address);
		printf("Function address %p\n",(char*)return_address+2);
		index = get_function((char*)return_address);
		if(index!=-1)
			printf("%s %p\n", functions[index].name, (int*)functions[index].addr);
		else
			printf("cant print\n"); 
		ebp=old_ebp;
		count++;
		if(count==3) break;
	}

	
}


