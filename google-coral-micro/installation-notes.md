## Using the Arduino IDE


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


Video about python installation installation here (not terrible useful, but interesting to see.

https://www.youtube.com/watch?v=yatapqfbIhA

Not many other videos

So on Ubuntu 20 LTS I downloaded the Arduino IDE 2.2.1 and unzipped it, loaded the above dev-rules in the preferences entered the above .json file and then tried to find the coral board and it doesn't show up. What! Ooops I was on lbraries not boards. That makes more sense.



First weird thing. On my new windows machine all library examples were installed but on Linux and my Schools windows machines only the first group of examples are installed.

I am starting to understand the short list is for the linux micro-coral. the large list is for the Arduino. But some Arduino installations just get the small list.


<img width="1000" alt="menu-coral-02-some" src="https://github.com/hpssjellis/mcu-stable-edu-launch/assets/5605614/8ac8c9e9-b00e-478f-a644-2fdc7338f54a">


So Tried facesDetect. Compiled really fast. plugged in the coral-micro. ran ```lsusb``` and it detected it. set the port in the arduino IDE and uploaded the code and it all worked. Then replugged in the micro and nothing. Orange LED that is is. No more port connection. DFU mode unresponsive. Uer button push while plugging in the USB.


Trying my Windows machine.

1. Windows Arduino IDE V1.8.19 loads board, compiles, does not show examples or upload errors on "paragraph"
2. Windows Arduino IDE 2.2.1 at school loads board and short version of examples. compiles and loads blink program
3. Windows Arduino IDE 2.2.1 on new home computer loads board and long version of examples. compiles and loads blink program 
3. Ubuntu Linux Arduino IDE 2.2.1 on old laptop running version 20.x LTS loads board and long short of examples. Compiles and loads blink program 

A. Generally ML code not working never seen the white LED for the TPU
B. POE did not work at home to power the board
C. POE worked at school to power board. The example I ran was kind of useless as it did not use a normal port and I could not viewe it on my local network. This is still kind of positive.
D. Face Detect compiled and uploaded but did not seem to run
E. TFLMHelloWorld worked but the output is not ready to show on the plotter. I did get results
F. No idea how to code the inner M4 core?



# Using Python

I have Python3 version 3.8.10
I have cmake version 3.16.3 but need version 3.18

```

wget https://github.com/Kitware/CMake/releases/download/v3.24.1/cmake-3.24.1-Linux-x86_64.sh \
  -q -O /tmp/cmake-install.sh \
&& chmod u+x /tmp/cmake-install.sh \
&& sudo mkdir /opt/cmake-3.24.1 \
&& sudo /tmp/cmake-install.sh --skip-license --prefix=/opt/cmake-3.24.1 \
&& rm /tmp/cmake-install.sh \
&& sudo ln -s /opt/cmake-3.24.1/bin/* /usr/local/bin

Then restaert computer and run

cmake --version

```



https://github.com/google-coral/coralmicro


```
Clone coralmicro and all submodules:

git clone --recurse-submodules -j8 https://github.com/google-coral/coralmicro


cd coralmicro && bash setup.sh


bash build.sh

python3 scripts/flashtool.py -e blink_led


You can see the code at examples/blink_led/.

Reset the board to Serial Downloader  (hold user button while pressing side button)



```

So all these examples are now pre-built and can be uploaded really fast by changing the flash command to any of these folder names

https://github.com/google-coral/coralmicro/tree/main/examples

```
python3 scripts/flashtool.py -e detect_faces
```

Useful commands:

Check the active COM port
```
ls /dev/ttyACM*
```

run screen to communicate with the COM port that has your coral-micro on

```
screen /dev/ttyACM0 115200
screen /dev/ttyACM1 115200
screen /dev/ttyACM2 115200
```

A couple of notes:

1. Always first plugin the coral-micro pushing the middle button. load your code and then unplug-replug the coral-micro to run the code. Other methods seem flacky, this method always works.
2.  
.

.

.

.

.

.

.

.

.

..

.



# RTOS
The following did not work for me
https://coral.ai/docs/dev-board-micro/freertos/#create-an-out-of-tree-project

Note: In the scripts/requirements.txt file the 

```
hidapi==0.10.1   change to    hidapi==0.11.2
```


These are the commands
```
git clone https://github.com/google-coral/coralmicro-out-of-tree-sample


cd coralmicro-out-of-tree-sample

git submodule add https://github.com/google-coral/coralmicro coralmicro

git submodule update --init --recursive
Install the required development tools (such as CMake) with this script:

bash coralmicro/setup.sh
That's it. You now have an out-of-tree project and you can start coding. Or continue to the next section and try flashing it to your board.

Build and flash
You can build and flash your out-of-tree project like this:

Generate the project Makefile (run this from the out-of-tree-sample root):

# -B specifies the path for your build output path and
# -S specifies the path to the CMakeLists.txt file.
cmake -B out -S .
Build the app:

make -C out -j4
To maximize your CPU usage, replace -j4 with either -j$(nproc) on Linux or -j$(sysctl -n hw.ncpu) on Mac.

Flash the app to your board:

python3 coralmicro/scripts/flashtool.py --build_dir out --elf_path out/coralmicro-app
coralmicro-app is the executable name that's specified in CMakeLists.txt, so that's the ELF file name you must specify with --elf_path.

Note: In addition to specifying the path to your ELF file with --elf_path, you must specify the build output directory with --build_dir because flashtool needs to get the elf_loader (bootloader) program from there. Whereas, when flashing in-tree examples and apps, --build_dir can be ommitted because flashtool uses the default in-tree "build" directory. Similarly, in-tree examples/apps don't need to specify elf_path because those files reside in the same build directory, so you can instead specify just the project name with --example (or -e) and --app (or -a).
When flashing is done, the board reboots and loads the app. You should see the green LED turn on. To see the "Hello World" message, connect to the serial console.

When you modify the source code or CMake configuration, just rebuild and reflash the app:

make -C out -j4

python3 coralmicro/scripts/flashtool.py --build_dir out --elf_path out/coralmicro-app


```


# General

resync with the coral-micro site

```
git fetch origin

git rebase origin/main

git submodule update --init --recursive
```







