# Minitalk_42
# 📡 Minitalk

Minitalk is a **simple message-passing project** implemented in **C** using UNIX signals. It allows communication between a client and a server using **SIGUSR1** and **SIGUSR2** signals to transmit data **bit by bit**.

## 🚀 Features
### ✅ Mandatory Part
- The **server** prints messages received from clients.
- The **client** sends a string to the server, one bit at a time.
- Messages are transmitted using only **SIGUSR1** and **SIGUSR2** signals.
- Server **displays the received message** on standard output.

### ✨ Bonus Features
- **Acknowledgment System**: The server sends a signal back to confirm receipt of each character.
- **Multiple Clients Support**: The server can handle messages from multiple clients.
- **Unicode Character Support**: Allows transmission of **extended characters** beyond ASCII (e.g., é, Ω, 𝄞).
- **Improved Signal Handling**: Uses `sigaction()` for better handling of signals.

---

## 🛠️ Functions Used
### **Mandatory**
- `kill()` → Sends signals between processes.
- `getpid()` → Retrieves the **process ID (PID)**.
- `pause()` → Waits for incoming signals.
- `signal()` → Handles incoming signals.
- `usleep()` → Controls signal transmission timing.
- `write()` → Displays received messages.

### **Bonus**
- `sigaction()` → Advanced signal handling with **siginfo_t**.
- `malloc()` → Manages multiple clients dynamically.
- `free()` → Releases memory after client communication ends.

---

## 🏗️ Compilation & Usage

### **1️⃣ Compile the project**
```sh
make
```
This generates **server** and **client** executables.

### **2️⃣ Start the server**
```sh
./server
```
This will display the **server PID**, which is required for the client to send messages.

### **3️⃣ Send a message from the client**
```sh
./client <server_pid> "Hello, Minitalk!"
```
Example:
```sh
./client 12345 "Hello, World!"
```
---

## 📷 Demo
### **1️⃣ Starting the Server**
```
$ ./server
Server PID 12345
```
### **2️⃣ Sending a Message**
```
$ ./client 12345 "Hello, Minitalk!"
Confirmation from server!
```
### **3️⃣ Server Output**
```
Hello, Minitalk!
```

**🌟 Bonus Features**
✅ Unicode Support
The bonus version allows sending UTF-8 characters (e.g., emojis, non-ASCII text) same as the mandatory.


./client_bonus 4242 "Élève Ω 🚀"
✅ Acknowledgment from Server
The server sends a confirmation signal after each message. The client receives and prints:


Confirmation from server! by : .............

✅ Multiple Clients Handling
Each client is handled independently without interference.

---

## 🏆 Bonus Features in Action
- Supports **multiple clients** sending messages.
- Handles **unicode characters** (e.g., `é`, `Ω`, `𝄞`).
- Acknowledges every received character.

---

## 👨‍💻 Author
Developed with ❤️ by **[SIMEON WANSI]**

📌 **GitHub**: (https://github.com/Simeon-wansi/)  
📌 **LinkedIn**: (https://www.linkedin.com/in/sim%C3%A9on-wansi/)

---

## 🎯 Future Improvements
- **Add error handling for invalid PIDs.**
- **Implement a queue system for better multi-client management.**
- **Enhance performance with optimized signal processing.**

---

📜** License
This project is licensed under the 42 Network norms.**

### ⭐ If you like this project, give it a **star** on GitHub! ⭐

