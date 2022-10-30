# ice-quaternion
This example showcases two processes that communicate with each other using zero-copy inter-process communication (IPC) on iceoryx.

## Expected Output
![expected_output](assets/ice-quaternion.png "Expected Output")

## Build and Run

1. First, iceoryx needs to be installed. You can find the build and installation guidelines [here](assets/installation.md).
2. Build (with CMake)
    1. Generate the necessary build files
   ```bash
   cd ice-quaternion
   cmake CMakelist.txt
    ```
    2. Compile the source code
   ```bash
   cmake --build .
    ```
3. How to run  
There are two ways how to start processes:
   - **Run sh script (fast way):**
      ```bash
     cd ice-quaternion
     ./run_ice_quaternion.sh 
      ```
   - **or start all processes manually in terminal:**
     1. Start RouDi Daemon in terminal
     ```bash
     iox-roudi
      ```
     2. Start publisher in separate terminal
     ```bash
     cd ice-quaternion
     ./ice-quaternion-publisher
      ```
     3. Start subscriber in separate terminal
     ```bash
     cd ice-quaternion
     ./ice-quaternion-subscriber
      ```
   
