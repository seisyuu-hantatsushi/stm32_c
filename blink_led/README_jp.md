# NEUCLEO-H7x5ZI-Q Sample
## 必要環境
- Ubuntu 20.04 LTS
- STM32CubeIDE  
  compilerを利用.
- openocd  
  version 12以降を利用. 
## 利用方法
- `stm32_c/blink_led/Makefile`へ移動する.  
   ```
   cd stm32_c/blink_led/Makefile
   ```
- STM32CubeIDE compilerとopenocdへのpathを設定する.
  `source ./build_env.sh`
- openocdを起動  
   ```
   $ openocd -f openocd_stmh7x5zi.cfg
   Open On-Chip Debugger 0.12.0+dev-00440-ge8e09b1b5 (2023-12-17-12:54)
   Licensed under GNU GPL v2
   For bug reports, read
	   http://openocd.org/doc/doxygen/bugs.html
   srst_only separate srst_nogate srst_open_drain connect_deassert_srst
   Info : Listening on port 6666 for tcl connections
   Info : Listening on port 4444 for telnet connections
   Info : STLINK V3J13M4 (API v3) VID:PID 0483:374E
   Info : Target voltage: 3.275331
   Info : Unable to match requested speed 1800 kHz, using 1000 kHz
   Info : Unable to match requested speed 1800 kHz, using 1000 kHz
   Info : clock speed 1000 kHz
   Info : stlink_dap_op_connect(connect)
   Info : SWD DPIDR 0x6ba02477
   Info : [stm32h7x.ap2] Examination succeed
   Info : [stm32h7x.cpu0] Cortex-M7 r1p1 processor detected
   Info : [stm32h7x.cpu0] target has 8 breakpoints, 4 watchpoints
   Info : [stm32h7x.cpu0] Examination succeed
   Info : [stm32h7x.cpu1] Cortex-M4 r0p1 processor detected
   Info : [stm32h7x.cpu1] target has 6 breakpoints, 4 watchpoints
   Info : [stm32h7x.cpu1] Examination succeed
   Info : gdb port disabled
   Info : starting gdb server for stm32h7x.cpu0 on 3333
   Info : Listening on port 3333 for gdb connections
   Info : starting gdb server for stm32h7x.cpu1 on 3334
   Info : Listening on port 3334 for gdb connections
   ```
- gdbにてCortext-M4側に接続
  1. terminalを起動してgdbを起動しCortex-M4に接続
     ```
     $ arm-none-eabi-gdb CM4/build/blink_led_CM4.elf
     GNU gdb (GNU Tools for STM32 11.3.rel1.20230912-1600) 12.1.90.20220802-git
     Copyright (C) 2022 Free Software Foundation, Inc.
     License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
     This is free software: you are free to change and redistribute it.
     There is NO WARRANTY, to the extent permitted by law.
     Type "show copying" and "show warranty" for details.
     This GDB was configured as "--host=x86_64-linux-gnu --target=arm-none-eabi".
     Type "show configuration" for configuration details.
     For bug reporting instructions, please see:
     <https://www.gnu.org/software/gdb/bugs/>.
     Find the GDB manual and other documentation resources online at:
         <http://www.gnu.org/software/gdb/documentation/>.
     
     For help, type "help".
     Type "apropos word" to search for commands related to "word"...
     Reading symbols from CM4/build/blink_led_CM4.elf...
     (gdb) target remote localhost:3334
     Remote debugging using localhost:3334
     Reset_Handler () at startup_stm32h755xx_CM4.s:61
     61     	  ldr   sp, =_estack      /* set stack pointer */
     ```
  2. 実行コードをFlashに書き込み
     ```
     (gdb) monitor reset halt
     [stm32h7x.cpu0] halted due to debug-request, current mode: Thread 
     xPSR: 0x01000000 pc: 0x08004360 msp: 0x20020000
     [stm32h7x.cpu1] halted due to debug-request, current mode: Thread 
     xPSR: 0x01000000 pc: 0x08102ac0 msp: 0x10048000
     (gdb) load
     Loading section .isr_vector, size 0x298 lma 0x8100000
     Loading section .text, size 0x28ec lma 0x8100298
     Loading section .rodata, size 0x4c lma 0x8102b84
     Loading section .ARM, size 0x8 lma 0x8102bd0
     Loading section .init_array, size 0x4 lma 0x8102bd8
     Loading section .fini_array, size 0x4 lma 0x8102bdc
     Loading section .data, size 0x10 lma 0x8102be0
     Start address 0x08102ac0, load size 11248
     Transfer rate: 7 KB/sec, 1606 bytes/write.
     ```
- gdbにてCortex-M7側に接続
  1. terminalを起動してgdbを起動しCortex-M7に接続
     ```
     $ arm-none-eabi-gdb CM7/build/blink_led_CM7.elf
     GNU gdb (GNU Tools for STM32 11.3.rel1.20230912-1600) 12.1.90.20220802-git
     Copyright (C) 2022 Free Software Foundation, Inc.
     License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
     This is free software: you are free to change and redistribute it.
     There is NO WARRANTY, to the extent permitted by law.
     Type "show copying" and "show warranty" for details.
     This GDB was configured as "--host=x86_64-linux-gnu --target=arm-none-eabi".
     Type "show configuration" for configuration details.
     For bug reporting instructions, please see:
     <https://www.gnu.org/software/gdb/bugs/>.
     Find the GDB manual and other documentation resources online at:
         <http://www.gnu.org/software/gdb/documentation/>.
     
     For help, type "help".
     Type "apropos word" to search for commands related to "word"...
     Reading symbols from CM7/build/blink_led_CM7.elf...
     (gdb) target remote localhost:3333
     Remote debugging using localhost:3333
     Reset_Handler () at startup_stm32h755xx_CM7.s:61
     61     	  ldr   sp, =_estack      /* set stack pointer */
     ```
  2. 実行コードをFlashに書き込み
     ```
     (gdb) monitor reset halt
     [stm32h7x.cpu0] halted due to debug-request, current mode: Thread 
     xPSR: 0x01000000 pc: 0x08004360 msp: 0x20020000
     [stm32h7x.cpu1] halted due to debug-request, current mode: Thread 
     xPSR: 0x01000000 pc: 0x08102ac0 msp: 0x10048000
     (gdb) load
     Loading section .isr_vector, size 0x298 lma 0x8000000
     Loading section .text, size 0x418c lma 0x8000298
     Loading section .rodata, size 0x4c lma 0x8004424
     Loading section .ARM, size 0x8 lma 0x8004470
     Loading section .init_array, size 0x4 lma 0x8004478
     Loading section .fini_array, size 0x4 lma 0x800447c
     Loading section .data, size 0x10 lma 0x8004480
     Loading section .RxDecripSection, size 0x60 lma 0x8004490
     Loading section .TxDecripSection, size 0x60 lma 0x80044f0
     Start address 0x08004360, load size 17744
     Transfer rate: 10 KB/sec, 1774 bytes/write.
     ```
- 各CPUを起動
  1. gdbにてCortex-M4側を起動
     起動後Cortex-M4はCortex-M7起動待ちでSleep Modeに入る. gdbからは`0xa05f0000`にて停止しているように見える.
     ```
     (gdb) monitor reset init
     [stm32h7x.cpu0] halted due to debug-request, current mode: Thread 
     xPSR: 0x01000000 pc: 0x08004360 msp: 0x20020000
     [stm32h7x.cpu1] halted due to debug-request, current mode: Thread 
     xPSR: 0x01000000 pc: 0x08102ac0 msp: 0x10048000
     Unable to match requested speed 4000 kHz, using 3300 kHz
     Unable to match requested speed 4000 kHz, using 3300 kHz
     (gdb) c
     Continuing.
     [stm32h7x.cpu1] clearing lockup after double fault
     
     Program received signal SIGINT, Interrupt.
     0xa05f0000 in ?? ()
     (gdb) 
     ```
   2. gdbにてCortex-M7側を起動
      Cortex-M4側での`reset init`にてCortex-M7も`reset init`される
      ```
      (gdb) c
      Continuing.
      [stm32h7x.cpu1] external resume detected
      [stm32h7x.cpu1] not halted
      [stm32h7x.cpu1] context restore failed, aborting resume
      target stm32h7x.cpu1 was not halted when resume was requested
      
      Program received signal SIGINT, Interrupt.
      0x08003316 in HAL_GetTick () at ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c:340
      340	  return uwTick;
      (gdb)
      ``` 
   3. gdbにてCortex-M4側を再開  
      ```
      (gdb) c
      Continuing.
      [stm32h7x.cpu1] not halted
      [stm32h7x.cpu1] context restore failed, aborting resume
      target stm32h7x.cpu1 was not halted when resume was requested
      ^C
      Program received signal SIGINT, Interrupt.
      0x08102076 in HAL_GetTick () at ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c:340
      340	  return uwTick;
      (gdb)
      ```
## 起動シーケンス概要
1. Cortex-M4側が起動後Hardware Semaphoreを初期化し,Cortex-M7側の初期待ち
2. Cortex-M7側が起動し,Hardware関連を初期化し,Hardware Semaphoreを取得,開放して,Cortex-M4側のWFEを解除
3. Cortex-M4側がHardware関連を初期化.
4. 両コアがMain Loopへ.

## 参考
[Debugging Initialization Code of Multi-Core STM32H7 Devices](https://visualgdb.com/tutorials/arm/stm32/multicore/startup/)
