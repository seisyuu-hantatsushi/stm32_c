# NEUCLEO-H7x5ZI-Q Sample
## 必要環境
- Ubuntu 20.04 LTS
- STM32CubeIDE  
  compilerを利用.
- openocd  
  version 12以降を利用. 
## 利用方法
- `stm32_c/dual_core_uart_makefile/Makefile`へ移動する.  
```
cd stm32_c/dual_core_uart_makefile/Makefile
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
