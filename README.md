# particle-uart-bluetooth

A Particle project named particle-uart-bluetooth to send AT+ commands to a bluetooth module on UART4.  Command is buffered and not sent until you press return.

## Sending commands

Note that the particle-serial-monitor is READ ONLY.  To send commands (on a mac) use SCREEN

From: https://community.particle.io/t/serial-tutorial/26946

    Find the serial port that is being used using the Terminal program command line:

    `ls /dev/cu.usb*`
    It should return something like /dev/cu.usbmodemFD1161.

    Then issue the command:

    `screen /dev/cu.usbmodemFD1161`

### ```/src``` folder:

This is the source folder that contains the firmware files for your project. It should *not* be renamed.
Anything that is in this folder when you compile your project will be sent to our compile service and compiled into a firmware binary for the Particle device that you have targeted.

If your application contains multiple files, they should all be included in the `src` folder. If your firmware depends on Particle libraries, those dependencies are specified in the `project.properties` file referenced below.

### ```.ino``` file:

This file is the firmware that will run as the primary application on your Particle device. It contains a `setup()` and `loop()` function, and can be written in Wiring or C/C++. For more information about using the Particle firmware API to create firmware for your Particle device, refer to the [Firmware Reference](https://docs.particle.io/reference/firmware/) section of the Particle documentation.

### ```project.properties``` file:

This is the file that specifies the name and version number of the libraries that your project depends on. Dependencies are added automatically to your `project.properties` file when you add a library to a project using the `particle library add` command in the CLI or add a library in the Desktop IDE.

## Adding additional files to your project

## Compiling your project

When you're ready to compile your project, make sure you have the correct Particle device target selected and run `particle compile <platform>` in the CLI or click the Compile button in the Desktop IDE. The following files in your project folder will be sent to the compile service:

- Everything in the `/src` folder, including your `.ino` application file
- The `project.properties` file for your project
- Any libraries stored under `lib/<libraryname>/src`
