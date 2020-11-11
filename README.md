# stm32_ros_chatter


## Requirements

```shell
 $ sudo apt install gcc-arm-none-eabi openocd
```

and ST-Link

https://github.com/stlink-org/stlink

# Burn
```shell
 $ openocd -f board/st_nucleo_f4.cfg
```

Open new terminal and
```
 $ telnet localhost 4444
> reset halt
> flash write_image erase build/ros_chatter.elf
> exit
```


## Run Chatter
make sure you have already installed ```rosserial```
if not, type following...
```
 $ sudo apt install ros-melodic-rosserial
```

run rosserial node
```
 $ rosrun rosserial_python serial_node.py _port:=/dev/ttyACM0
```
