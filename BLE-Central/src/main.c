#include "central.h"

void main(void)
{
	int err = bt_enable(NULL);
	if (err) {
		printk("Bluetooth init failed (err %d)\n", err);
		return;
	}

	printk("Bluetooth initialized\n");
	
	err = bt_set_name("Central");
	if (err) {
        printk("Failed to set device name (err %d)\n", err);
        return;
    }
	
	start_scan();
	read_input();
}