#!/bin/sh
module="scull"
device="scull"

# invoke rmmod with all argument we got
/sbin/rmmod $module $* || exit 1

# remove nodes
rm -f /dev/${device}[0-3] /dev/${device}

exit 0
