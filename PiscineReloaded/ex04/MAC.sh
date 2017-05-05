ifconfig -a | grep ether | sed 's/ether//' | cut -c 3- | sed 's/ //'
