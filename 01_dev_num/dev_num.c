/****************************************************************************************************************************//**
*   \file                       dev_num.c
*
*   \details                    Import device number: Major and minor
*
*   \author                     Duc Nguyen Chi
*
* ******************************************************************************************************************************/

#include <linux/module.h>
#include <linux/fs.h>

#define DRIVER_AUTHOR "ducnguyen090999@gmail.com"
#define DRIVER_DESC "Register a device numer and implement callback function"
#define DRIVER_VERS "1.0"

#define MY_MAJOR    95

/*
 * @brief                   This function is called when the device file is opened
 * @param[in]               device_file         inode of device file
 * @param[out]              instance            instance of file
 */
static int driver_open(struct inode *device_file, struct file *instance)
{
    printk(KERN_INFO "dev_nr - open device file ops was called\n");
    return 0;
}

/*
 * @brief                   This function is called when the device file is closed
 * @param[in]               device_file         inode of device file
 * @param[out]              instance            instance of file
 */
static int driver_close(struct inode *device_file, struct file *instance)
{
    printk(KERN_INFO "dev_nr - close device file ops was called\n");
    return 0;
}

static struct file_operations fops = 
{
    .owner = THIS_MODULE,
    .open = driver_open,
    .release = driver_close
};

/*
 * @brief                   Execute first when the linux device driver is loaded into the kernel
 * @param[in]               None
 * @param[out]              None
 */

static int 
__init register_device_number_init(void){
    int ret_val;
    printk(KERN_INFO "Initialize register device number linux kernel module\n");
    ret_val = register_chrdev(MY_MAJOR,"my_dev-nr", &fops);
    if (ret_val == 0)
    {
        printk(KERN_INFO "dev_nr - registered device number. Major: %d, Minor: %d\n", MY_MAJOR,0);
    }
    else if (ret_val > 0)
    {
        printk(KERN_INFO "dev_nr - registered device number. Major: %d, Minor: %d\n", ret_val >> 20,ret_val&0xFFFF);
    }
    else
    {
        printk(KERN_INFO "Could not register device number\n");
    }
    return 0;
}


/*
 * @brief                   Execute last when the linux device driver is loaded into the kernel
 * @param[in]               None
 * @param[out]              None
 */
static void 
__exit register_device_number_exit(void){
    printk(KERN_INFO "exit register device number linux kernel module\n");
    unregister_chrdev(MY_MAJOR, "my_dev_nr");
}

module_init(register_device_number_init);
module_exit(register_device_number_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_VERSION(DRIVER_VERS);


/*
 * @info
 * Cat /proc/devices to see all assigned major.
 * Do not assign existed major 
 * */