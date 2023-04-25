#include<linux/module.h>
#include<linux/kernel.h>
#include <linux/moduleparam.h>

int param_var=0;
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Attreyee Mukherjee");
MODULE_DESCRIPTION("A simple hello world module");
MODULE_VERSION("0.01");

module_param(param_var,int, S_IRUSR | S_IWUSR);

static int __init hello_mod_init(void)
{
        printk(KERN_ALERT "Hello world from kernel!! \n");
        printk(KERN_ALERT "paramater passed = %d\n",param_var);
        
        return 0;
}

static void __exit hello_mod_exit(void)
{
        printk(KERN_ALERT "Exiting hello world module from kernel !!!\n");
}

module_init(hello_mod_init);
module_exit(hello_mod_exit);
