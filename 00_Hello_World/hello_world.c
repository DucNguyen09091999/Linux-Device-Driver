/****************************************************************************************************************************//**
*   \file                       first_driver.c
*
*   \details                    first driver linux kernel module
*
*   \author                     Duc Nguyen Chi
*
* ******************************************************************************************************************************/

#include <linux/module.h>
#include <linux/fs.h>

#define DRIVER_AUTHOR "ducnguyen090999@gmail.com"
#define DRIVER_DESC "First driver linux kernel module"
#define DRIVER_VERS "1.0"


/*
 * @brief                   Execute first when the linux device driver is loaded into the kernel
 * @param[in]               None
 * @param[out]              None
 */

static int 
__init first_driver_init(void){
    printk(KERN_INFO "Initialize first driver linux kernel module\n");
    return 0;
}


/*
 * @brief                   Execute last when the linux device driver is loaded into the kernel
 * @param[in]               None
 * @param[out]              None
 */
static void 
__exit first_driver_exit(void){
    printk(KERN_INFO "exit first driver linux kernel module\n");
}

module_init(first_driver_init);
module_exit(first_driver_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_VERSION(DRIVER_VERS);


/*
 * @info
 * KERN_EMERG: Used for emergency messages, usually those that precede a crash.
 * KERN_ALERT: A situation requiring immediate action.
 * KERN_CRIT: Critical conditions are often related to serious hardware or software failures.
 * KERN_ERR: Used to report error conditions; device drivers often use KERN_ERR to report hardware difficulties.
 * KERN_WARNING: Warnings about problematic situations that do not, in themselves, create serious problems with the system.
 * KERN_NOTICE: Situations that are normal, but still worthy of note. A number of security-related conditions are reported at this level.
 * KERN_INFO: Informational messages. Many drivers print information about the hardware they find at startup time at this level.
 * KERN_DEBUG: sed for debugging messages.
 * */