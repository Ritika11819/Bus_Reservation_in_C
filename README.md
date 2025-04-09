# Bus_Reservation_in_C

This project is a **console-based Bus Reservation System**  written in C. It provides users with the ability to **register, log in, view routes and seats, book tickets, cancel bookings, modify passenger details, and view their booking history** — all in one simple terminal interface.

---

###  Features

1. **User Registration and Login**
   - New users can register with a username and password.
   - Registered users can log in to access reservation features.
   - Username uniqueness is enforced.

2. **Route Display**
   - Displays a list of 6 predefined bus routes, each with its own schedule.

3. **Seat Booking**
   - Automatically allocates the next available seat.
   - Allows entry of passenger details like name, age, gender, and route.
   - Saves a copy of all bookings in a booking history.

4. **Seat Display**
   - Shows available seats for a particular route.
   - Helps users check availability before booking.

5. **Ticket Cancellation**
   - Users can cancel a ticket by entering their route name and seat number.
   - Confirmation is required before cancellation.
   - Seats are reallocated appropriately after cancellation.

6. **Booking History**
   - Displays a list of all bookings made during the session.

7. **Ticket Modification**
   - Allows users to modify details of an existing ticket (name, age, gender, route).
   - Validation ensures the seat must be booked to allow modification.

---

### Technologies Used

- **Language:** C
- **Data Structures:** Arrays and Structures (`struct`)
- **IDE/Compiler:** Any C-supported IDE ( GCC,VS Code)

---

### 🧪 How to Run

1. Open a C IDE or terminal.
2. Compile the code:
   ```bash
   gcc main.c -o bus
   ./bus
   ```
3. Follow the on-screen prompts to interact with the system.

### File Structure

- `main.c`: Contains the full implementation of the bus reservation system.
- `README.md`: Contains documentation of the project.



### Author
Heer Patel
Ritika Jiandani  
B.Tech CSE | Nirma University
