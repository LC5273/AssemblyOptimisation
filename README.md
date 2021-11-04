# AssemblyOptimisation

![build](https://img.shields.io/badge/build-passing-brightgreen)
![license](https://img.shields.io/github/license/LC5273/FireStorm-Game-Engine)
![platform](https://img.shields.io/badge/Platform-win--32-brightgreen)

  The aim of this project is to over-optimise code written in C/C++ in order to get a better runtime. For this purpose, we will use inline assembly injection directly into C++ sources and we will have a custom visual benchmarking for result analisys.
  
## Installation
  - (we will need Chrome browser installed - or any other tracing tool)
  - In order to run this code, you will need the [Visual Studio IDE](https://visualstudio.microsoft.com/) installed on a windows platform

## Running the application
  * Once you have Visual Studio installed and the code downloaded, double click on **FireStorm_Assembly_Optimization.sln**
  * NOTE - code should be run on the following setup: Debug X86 (the assembler optimization was done for 32-bit Windows compilation)
  * Run the code using the **green** button in the upper side of the IDE - **Local Windows Debugger**.
  * After the code runs, in the FireStorm_Assembly_Optimization/FireStorm_Assembly_Optimization folder, we will find the newly created JSON file
  * Open a chrome browser tab and write: [chrome://tracing](chrome://tracing)
  * Just drag-n-drop the **results.json** file into the chrome tab for visual benchmarking and analyse the results

## References
  * [Agner Fog - Optimizing Assembly](https://www.agner.org/optimize/optimizing_assembly.pdf)
