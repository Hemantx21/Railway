# 🚂 Railway Reservation System

A console-based Railway Reservation System built in C, simulating a real-world train booking experience with admin and user roles, ticket management, and persistent data storage — themed around **Gorakhpur Junction (GKP)**.

---

## 📋 Table of Contents

- [Features](#features)
- [Train Details](#train-details)
- [Getting Started](#getting-started)
- [How to Run](#how-to-run)
- [Login Credentials](#login-credentials)
- [Admin Menu](#admin-menu)
- [User Menu](#user-menu)
- [File Structure](#file-structure)
- [Data Files](#data-files)
- [Known Limitations](#known-limitations)

---

## ✨ Features

- Dual login system — **Admin** and **User** roles
- Train ticket **booking** with passenger details
- Ticket **cancellation**
- **Fare calculation** based on train and number of passengers
- **Seat availability** check (randomized simulation)
- Admin **profile settings** — add/delete/view admins
- **Railway database** management — add/delete trains
- **Persistent storage** — data saved to `.dat` files
- Colorful terminal output using ANSI escape codes

---

## 🚆 Train Details

| No. | Train Name            | Route                        | Fare (per person) | Departure |
|-----|-----------------------|------------------------------|-------------------|-----------|
| 1   | Gorakhpur Express     | Gorakhpur → Lucknow          | ₹350              | 06:00     |
| 2   | Gorakhpur Express     | Lucknow → Gorakhpur          | ₹350              | 14:00     |
| 3   | Sapt Kranti Express   | Gorakhpur → New Delhi        | ₹1200             | 20:00     |
| 4   | Sapt Kranti Express   | New Delhi → Gorakhpur        | ₹1200             | 07:45     |
| 5   | Gorakhpur-Mumbai Exp  | Gorakhpur → Mumbai           | ₹2200             | 13:30     |
| 6   | Gorakhpur-Mumbai Exp  | Mumbai → Gorakhpur           | ₹2200             | 09:15     |
| 7   | Kashi Vishwanath Exp  | Gorakhpur → Varanasi         | ₹280              | 08:30     |
| 8   | Kashi Vishwanath Exp  | Varanasi → Gorakhpur         | ₹280              | 17:00     |
| 9   | Nautanwa Express      | Gorakhpur → Kolkata          | ₹1800             | 22:15     |
| 10  | Nautanwa Express      | Kolkata → Gorakhpur          | ₹1800             | 05:30     |

---

## 🚀 Getting Started

### Prerequisites

- Windows OS
- [MinGW (GCC compiler)](https://www.mingw-w64.org/downloads/) installed and added to PATH
- [Visual Studio Code](https://code.visualstudio.com/) (recommended editor)

### VS Code Extensions (recommended)

- **C/C++** by Microsoft
- **Code Runner** by Jun Han

---

## ▶️ How to Run

1. Open the project folder in VS Code
2. Press **Ctrl + `** to open the terminal
3. Compile the program:

```bash
gcc main.c -o main
```

4. Run the program:

```bash
.\main.exe
```

> **Note:** Use `.\main.exe` in PowerShell (not just `main.exe`). PowerShell requires `.\` to run executables from the current directory.

---

## 🔐 Login Credentials

### Default Admin Accounts

| Username | Password |
|----------|----------|
| `hemant` | `pass1`  |
| `rupesh` | `pass2`  |
| `atul`   | `pass3`  |

> Passwords are hidden with `*` while typing.
> New admins can be added via **Profile Settings** in the Admin menu (slots 4, 5, 6 are available).
> Credentials are stored in `admins.dat` and persist between sessions.

---

## 🛠️ Admin Menu

After logging in as Admin, the following options are available:

| Option | Feature |
|--------|---------|
| 1 | Calculate Fare |
| 2 | Check Seat Availability |
| 3 | Book Ticket & Display Booked Tickets |
| 4 | Cancel Ticket |
| 5 | Profile Settings (Add/Delete/View Admins) |
| 6 | Railway Database (Add/Delete/View Trains) |
| 7 | View All Booked Tickets |
| 0 | Exit |

---

## 👤 User Menu

Users do not need to log in. Options available:

| Option | Feature |
|--------|---------|
| 1 | Book Ticket & Display Booked Tickets |
| 2 | Fare Details |
| 3 | Check Seat Availability |
| 4 | Cancel Ticket |
| 5 | View Booked Tickets |
| 0 | Exit |

---

## 📁 File Structure

```
Mini Project/
│
├── main.c          ← Main source code
├── main.exe        ← Compiled executable (after running gcc)
├── admins.dat      ← Saved admin credentials (auto-generated)
├── trains.dat      ← Saved custom train data (auto-generated)
├── passengers.dat  ← Saved passenger details (auto-generated)
└── tickets.dat     ← Saved booked tickets (auto-generated)
```

---

## 💾 Data Files

The program automatically creates and reads these binary `.dat` files:

| File | Contents |
|------|----------|
| `admins.dat` | Admin usernames and passwords |
| `trains.dat` | Dynamically added train records |
| `passengers.dat` | Passenger booking details |
| `tickets.dat` | All booked ticket records |

> If these files are missing on first run, the program will display a "No data found" message and create them fresh on exit.

---

## ⚠️ Known Limitations

- Uses `conio.h` — **Windows only** (not compatible with Linux/Mac without modification)
- Seat availability is **randomly generated** (simulation only)
- Maximum of **6 admin accounts** and **10 custom trains**
- Maximum of **10 passengers** per session
- Built for educational/mini project purposes

---

## 👨‍💻 Built With

- **Language:** C
- **Compiler:** GCC (MinGW)
- **Platform:** Windows
- **Storage:** Binary file I/O (`.dat` files)
- **Terminal Colors:** ANSI escape codes

---

*Railway Reservation System — Mini Project*
