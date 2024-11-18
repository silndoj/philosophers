---

# Philosophers

## 📖 Overview

The **Philosophers** project is a simulation of the classic "Dining Philosophers Problem." It is designed to teach threading, synchronization, and inter-process communication concepts in C. The project focuses on implementing solutions using threads and mutexes (mandatory part) and processes and semaphores (bonus part).

---

## 🚀 Features

- Simulates philosophers alternating between eating, thinking, and sleeping.
- Prevents data races and starvation using mutexes and semaphores.
- Handles logging of philosopher states with precise timestamps.
- Two versions:
  - **Mandatory**: Uses threads and mutexes.
  - **Bonus**: Uses processes and semaphores.

---

## 🛠️ Project Structure

```plaintext
philosophers/
├── philo/           # Mandatory part
│   ├── *.c          # Source files
│   ├── *.h          # Header files
│   └── Makefile     # Build rules
├── philo_bonus/     # Bonus part
│   ├── *.c          # Source files
│   ├── *.h          # Header files
│   └── Makefile     # Build rules
└── README.md        # Project documentation
```

---

## ⚙️ Requirements

- **Programming Language**: C
- **Libraries**: pthreads
- **Compiler Flags**: `-Wall -Wextra -Werror`

---

## 📋 Instructions

### Mandatory Part

1. Clone the repository:
   ```bash
   git clone https://github.com/silndoj/philosophers.git
   cd philosophers/philo
   ```
2. Compile the program:
   ```bash
   make
   ```
3. Run the simulation:
   ```bash
   ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
   ```

### Bonus Part

1. Navigate to the bonus directory:
   ```bash
   cd philosophers/philo_bonus
   ```
2. Compile the program:
   ```bash
   make
   ```
3. Run the simulation:
   ```bash
   ./philo_bonus <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
   ```

---

## 📑 Rules and Constraints

- Each philosopher must avoid starving.
- Forks are shared resources; synchronization is crucial.
- Logs must:
  - Include timestamps in milliseconds.
  - Display state changes like "taking a fork," "eating," "sleeping," and "thinking."
  - Be accurate and avoid overlap.

---

## 🌟 Bonus Features

- Use of semaphores to manage shared resources (forks).
- Forks are not tied to specific philosophers but tracked collectively.
- Philosophers are represented as individual processes.

---

## 🧠 Learning Outcomes

- Understanding multithreading and process-based programming.
- Gaining experience with synchronization primitives (mutexes, semaphores).
- Handling resource sharing and avoiding deadlocks.

---
