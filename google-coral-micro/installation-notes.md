
Coral-micro notes say install to Arduino IDE version 2.x on Linux or Mac

Preference 
``` 
https://dl.google.com/coral/micro/package_coral_index.json
```

I tried on Windows with the old Arduino IDE 1.8.1 and it the board would not even install.

I tired on Linux with version 1.8.15 and it installed fine but the examples did not show up.


I tired on 2 of my school computers Arduino IDE version 2.2.x and it installed fine but with only half of the examples.


I tired on my home Windows with Arduino Version 2.2.x and it installed fine with all examples


I am trying on Linux with Arduino IDE version 2.2.x

I downloaded the zipped version and installed these devrules using a terminal

```
curl -OL https://dl.google.com/coral/micro/99-coral-micro.rules

sudo cp 99-coral-micro.rules /etc/udev/rules.d

sudo udevadm control --reload-rules

sudo udevadm trigger
```


Video about python installation installation here (not terrible useful, but intereting to see.

https://www.youtube.com/watch?v=yatapqfbIhA

Not many other videos

So on Ubuntu 20 LTS I downloaded the Arduino IDE 2.2.1 and unzipped it, loaded the above dev-rules in the preferences entered the above .json file and then tried to find the coral board and it doesn't show up. What! Ooops I was on lbraries not boards. That makes more sense.



