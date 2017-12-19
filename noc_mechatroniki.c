#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
 
MODULE_LICENSE("GPL");              ///< Licencja
MODULE_AUTHOR("Pawel Gajewski");      ///< Autor
MODULE_DESCRIPTION("Modul kernelowy na Noc Mechatroniki.");  ///< Opis
MODULE_VERSION("0.1");              ///< The version of the module
 
static char *name = "Magister Rawski";        ///< Argument przy ladowaniu, "world" - wartość domyślna.
module_param(name, charp, S_IRUGO); ///< Deklaracja, ze zmienna jest parametrem modulu
MODULE_PARM_DESC(name, "The name to display in /var/log/kern.log");  ///< parameter description
 
/** @brief The LKM initialization function
 *  The static keyword restricts the visibility of the function to within this C file. The __init
 *  macro means that for a built-in driver (not a LKM) the function is only used at initialization
 *  time and that it can be discarded and its memory freed up after that point.
 *  @return returns 0 if successful
 */
static int __init mchtr_night_init(void){
   printk(KERN_INFO "Noc Mechatroki: Mechatronki programują!\n Powiedział: %s\n", name);
   return 0;
}
 
/** @brief The LKM cleanup function
 *  Similar to the initialization function, it is static. The __exit macro notifies that if this
 *  code is used for a built-in driver (not a LKM) that this function is not required.
 */
static void __exit mchtr_night_exit(void){
   printk(KERN_INFO "Noc Mechatroniki: Mechatronki mowia \"papa\"\n Powiedział: %s\n", name);
}
 
/** @brief A module must use the module_init() module_exit() macros from linux/init.h, which
 *  identify the initialization function at insertion time and the cleanup function (as
 *  listed above)
 */
module_init(mchtr_night_init);
module_exit(mchtr_night_exit);