# RobotArmsBlockSimulator

1. Project Overview

The Arms_Chaos project is a C++ simulation of a dual-robotic-arm system designed to rearrange blocks between two locations (L1 and L2). It transforms an initial state into a user-defined final state 
through robotic operations like pickup, move, and stack.

This simulation models real-world logistics automation and manufacturing assembly line operations where robotic arms coordinate to manipulate objects.

2. Key Features

Block Manipulation – Supports Pickup, Unstack, Stack, Move, and PutDown operations. 
Real-Time State Tracking – Displays each step as the robotic arms move blocks. 
User-Friendly Input – Users specify initial and final block arrangements. 
Multi-Agent Coordination – Simulates two robotic arms (R1 & R2) working in parallel.

3. How It Works

Step 1: Input Parsing
The user defines the initial and final state of blocks at L1 and L2.
Blocks are represented as characters (e.g., A, B, C).

Step 2: State Comparison
The program iterates through the final state to check:
If the block is already in place → No action needed.
If the block is misplaced → Calls Actn_Blk() to move it.

Step 3: Action Execution (Actn_Blk())
Clears blocks above the target block (Unstack/Pickup).
Moves the block to the desired location (Move, Stack, PutDown).
Repeats until the final state matches the target configuration.

Step 4: Visualization (Prnt_St())
Blocks are displayed vertically (bottom-to-top).
Shows robotic arm actions (e.g., R1: A → Arm 1 is holding block A).

4. Real-World Application Usage:

Warehouse Automation (Sorting Packages 📦): Warehouses like UPS, Walmart use robotic arms to sort packages onto conveyor belts for delivery.
Car Manufacturing (Assembling Parts 🚗): Auto manufacturing warehouses can use robotic arms to place and secure car parts like doors and engines.
Smartphone Production (Component Placement 📱): Mobile phone spares warehouses can use robotic arms to place microchips, batteries, and screens onto phones.
Pharmaceutical Packaging (Medicine Sorting 💊): Pharma Industries can use robotic arms to place vaccine vials into packages for shipping.

5. How to Use Locally

Step 1: Clone and Compile:
git clone https://github.com/vinesh509/RobotArmsBlockSimulator
cd RobotArmsBlockSimulator
g++ Block_simulator_arms.cpp -o Block_simulator_arms

Step 2: Run
./Block_simulator_arms

Step 3: Follow Input Prompts

Define the initial and final state of blocks at L1/L2.
The program automatically rearranges blocks step-by-step.

6. Limitations
 
Max 15 Blocks – Due to fixed-size arrays (St_Ini[2][15]).
No Validation – The program does not check if the final state is logically possible (e.g., cyclic dependencies).
Single-Threaded Execution – The robotic arms operate sequentially, not truly in parallel.

7. Future Enhancements

Add a GUI – To visualize block movement instead of plain text output.
Implement Input Validation – To prevent incorrect or impossible states.
Allow Parallel Arm Actions – For faster execution and improved efficiency.

8. Contribution Guidelines

Fork the Repository
Add Features (e.g., GUI, input validation, dynamic block limits).
Submit a Pull Request with detailed documentation.

9. License & Contact

🔓 MIT License – Open-source.
Author: Vinesh Vangapandu
📧 Contact: vinesh509@gmail.com
🔗 GitHub Repository: https://github.com/vinesh509/RobotArmsBlockSimulator


