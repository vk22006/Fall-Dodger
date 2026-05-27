
# Fall Dodger

A simple arcade-style dodger game built using C++ and Raylib as part of my game development learning journey.

## Goal

- Practice gameplay programming fundamentals
- Improve understanding of collision systems and entity management
- Learn scalable game structure before transitioning into ECS architecture

## Gameplay

Control the paddle and dodge falling enemy blocks for as long as possible.

### Controls

- `A` → Move Left
- `D` → Move Right
- `P` → Pause Game
- `R` → Resume Game
- `ENTER` → Return to Title Screen after Game Over

## Features

- Delta time based movement
- Random enemy spawning
- Multiple enemy entities using `std::vector`
- Dynamic difficulty scaling over time
- Collision detection system
- Pause / Resume state
- Title screen and Game Over state
- Score system based on survival time
- Reset and respawn systems

## Concepts Practiced

- Game loop structure (`Input → Update → Render`)
- State management
- AABB collision detection
- Multi-entity iteration
- Frame-independent gameplay
- Entity-based class organization
- Dynamic gameplay scaling

## Tech Stack

- C++
- Raylib

## Project Structure

```text
Ball / Enemy Logic
Paddle Logic
Game State Management
Collision Systems
Rendering Systems
````

## Notes

This project is part of my long-term progression toward:

* Gameplay programming
* Mathematical intuition for game systems
* ECS architecture
* Custom engine development

The focus of this project was learning and experimentation rather than visual polish.

## Status

✅ Completed



